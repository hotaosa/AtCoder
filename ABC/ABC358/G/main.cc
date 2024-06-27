#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template <class T>
inline bool ChangeMax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int h, w, k, sr, sc;
  cin >> h >> w >> k >> sr >> sc;
  --sr, --sc;

  vector<int> dr = {1, 0, -1, 0};
  vector<int> dc = {0, 1, 0, -1};

  vector a(h, vector<ll>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
    }
  }

  int siz = min(h * w, k + 1);
  vector dp(siz, vector(h, vector<ll>(w, -1)));
  dp[0][sr][sc] = 0;

  ll res = a[sr][sc] * k;
  for (int i = 0; i < siz - 1; ++i) {
    for (int r = 0; r < h; ++r) {
      for (int c = 0; c < w; ++c) {
        if (dp[i][r][c] < 0) continue;
        for (int d = 0; d < 4; ++d) {
          int nr = r + dr[d];
          int nc = c + dc[d];
          if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
          if (ChangeMax(dp[i + 1][nr][nc], dp[i][r][c] + a[nr][nc])) {
            res = max(res, dp[i + 1][nr][nc] + (k - i - 1) * a[nr][nc]);
          };
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}