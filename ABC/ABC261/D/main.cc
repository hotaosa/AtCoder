#include <iostream>
#include <vector>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;  
  vector<long long> x(n), y(n + 1, 0);
  for (auto &p : x) cin >> p;
  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    cin >> y[c];
  }

  vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, -1));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dp[i][j] == -1) continue;
      chmax(dp[i + 1][j + 1], dp[i][j] + x[i] + y[j + 1]);
      chmax(dp[i + 1][0], dp[i][j]);
    }
  }

  long long res = 0;
  for (auto r : dp[n]) chmax(res, r);
  cout << res << endl;
  return 0;
}