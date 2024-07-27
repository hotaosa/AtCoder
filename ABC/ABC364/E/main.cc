#include <iostream>
#include <vector>

using namespace std;
constexpr int INF = 1 << 30;

void ChangeMin(int &a, int b) { a = min(a, b); }

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  int res = 0;
  vector dp(n + 1, vector<int>(x + 1, INF));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      for (int k = 0; k + a[i] <= x; ++k) {
        if (dp[j][k] + b[i] <= y) {
          ChangeMin(dp[j + 1][k + a[i]], dp[j][k] + b[i]);
          res = max(res, j + 1);
        }
      }
    }
  }

  if (res < n) ++res;
  cout << res << endl;
  return 0;
}