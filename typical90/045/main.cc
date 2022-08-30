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

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  vector<vector<long long> > dist(n, vector<long long>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    }
  }

  vector<long long> max_dist(1 << n, 0);
  for (int bit = 0; bit < (1 << n); ++bit) {
    vector<int> node_list;
    for (int i = 0; i < n; ++i) if (bit & (1 << i)) node_list.push_back(i);
    for (int i = 0; i < (int)node_list.size() - 1; ++i) {
      for (int j = 0; j < (int)node_list.size(); ++j) {
        chmax(max_dist[bit], dist[node_list[i]][node_list[j]]);
      }
    }
  }

  vector<vector<long long> > dp(k + 1, vector<long long>(1 << n, INF));
  dp[0][0] = 0;

  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j < (1 << n); ++j) {
      for (int k = j; k > 0; k = (k - 1) & j) {
        chmin(dp[i][j], max(dp[i - 1][j - k], max_dist[k]));
      }      
    }
  }

  cout << dp[k][(1 << n) - 1] << endl;
  return 0;
}
