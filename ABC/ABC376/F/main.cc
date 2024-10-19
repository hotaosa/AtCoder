#include <algorithm>
#include <iostream>
#include <vector>

inline void ChangeMin(int &a, int b) { a = std::min(a, b); }

int main() {
  int n, q;
  std::cin >> n >> q;

  std::vector<char> h(q);
  std::vector<int> t(q);
  for (int i = 0; i < q; ++i) {
    std::cin >> h[i] >> t[i];
    --t[i];
  }

  constexpr int INF = 1 << 30;
  std::vector<int> dp(n, INF);
  dp[0] = 0;

  for (int i = 0; i < q; ++i) {
    std::vector<int> ndp(n, INF);
    for (int j = 0; j < n; ++j) {
      if (dp[j] == INF) continue;
      int l = 0, r = 1;
      if (i > 0) {
        l = h[i - 1] == 'L' ? t[i - 1] : j;
        r = h[i - 1] == 'L' ? j : t[i - 1];
      }
      {
        int dl = (t[i] - l + n) % n;
        int dr = (t[i] - r + n) % n;
        if (h[i] == 'L') {
          if (dl < dr) {
            ChangeMin(ndp[r], dp[j] + dl);
          } else {
            ChangeMin(ndp[(t[i] + 1) % n], dp[j] + dl + dr + 1);
          }
        } else {
          if (dr < dl) {
            ChangeMin(ndp[l], dp[j] + dr);
          } else {
            ChangeMin(ndp[(t[i] + 1) % n], dp[j] + dl + dr + 1);
          }
        }
      }
      {
        int dl = (l - t[i] + n) % n;
        int dr = (r - t[i] + n) % n;
        if (h[i] == 'L') {
          if (dl < dr) {
            ChangeMin(ndp[r], dp[j] + dl);
          } else {
            ChangeMin(ndp[(t[i] - 1 + n) % n], dp[j] + dl + dr + 1);
          }
        } else {
          if (dr < dl) {
            ChangeMin(ndp[l], dp[j] + dr);
          } else {
            ChangeMin(ndp[(t[i] - 1 + n) % n], dp[j] + dl + dr + 1);
          }
        }
      }
    }
    dp = std::move(ndp);
  }

  std::cout << *std::min_element(std::begin(dp), std::end(dp)) << "\n";
  return 0;
}