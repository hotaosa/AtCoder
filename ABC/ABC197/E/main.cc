#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}
template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int vcomp(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz = 1;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

int main() {
  int n;
  cin >> n;
  vector<long long> x(n);
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> c[i];
  int c_size = vcomp(c);

  vector<vector<long long> > edge(c_size, vector<long long>(2, -1));
  edge[0][0] = edge[0][1] = 0;
  for (int i = 0; i < n; ++i) {
    if (edge[c[i]][0] == -1) edge[c[i]][0] = edge[c[i]][1] = x[i];
    else {
      chmin(edge[c[i]][0], x[i]);
      chmax(edge[c[i]][1], x[i]);
    }
  }  

  vector<vector<long long> > dp(c_size, vector<long long>(2, INF));
  dp[0][0] = 0;
  dp[0][1] = 0;

  for (int i = 1; i < c_size; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        chmin(dp[i][j], dp[i - 1][k] + abs(edge[i][j ^ 1] - edge[i - 1][k]) + abs(edge[i][j] - edge[i][j ^ 1]));
      }
    }
  }    

  long long res = INF;
  for (int i = 0; i < 2; ++i) chmin(res, dp[c_size - 1][i] + abs(edge[c_size - 1][i]));
  cout << res << endl;
  return 0;
}
