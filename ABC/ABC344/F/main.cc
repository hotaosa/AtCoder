#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr long long INF = 1LL << 60;

template <class T>
inline bool ChangeMin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector p(n, vector<ll>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> p[i][j];
    }
  }

  vector c(n, vector(n, vector<ll>(2)));
  for (int k = 1; k >= 0; --k) {
    for (int i = 0; i < n - (k ^ 1); ++i) {
      for (int j = 0; j < n - k; ++j) {
        cin >> c[i][j][k];
      }
    }
  }

  array<int, 2> dx = {1, 0}, dy = {0, 1};
  vector dp(n, vector(n, vector(n, vector<pair<ll, ll> >(n, {INF, INF}))));
  dp[0][0][0][0] = {0, 0};
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      for (int xm = 0; xm <= x; ++xm) {
        for (int ym = 0; ym <= y; ++ym) {
          if (dp[x][y][xm][ym].first == INF) continue;
          for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx == n || ny == n) continue;
            int nxm = xm, nym = ym;
            if (p[nx][ny] > p[xm][ym]) {
              nxm = nx;
              nym = ny;
            }
            auto [count, money] = dp[x][y][xm][ym];
            if (-money < c[x][y][i]) {
              int add = (c[x][y][i] + money + p[xm][ym] - 1) / p[xm][ym];
              money -= add * p[xm][ym];
              count += add;
            }
            ChangeMin(dp[nx][ny][nxm][nym], {count + 1, money + c[x][y][i]});
          }
        }
      }
    }
  }

  ll res = INF;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ChangeMin(res, dp[n - 1][n - 1][i][j].first);
    }
  }
  cout << res << endl;
  return 0;
}