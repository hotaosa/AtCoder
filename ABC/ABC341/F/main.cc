#include <algorithm>
#include <iostream>
#include <numeric>
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
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  vector<int> w(n);
  vector<ll> a(n);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].emplace_back(--v);
    graph[v].emplace_back(u);
  }

  for (auto &e : w) cin >> e;
  for (auto &e : a) cin >> e;

  vector<int> o(n);
  iota(o.begin(), o.end(), 0);
  sort(o.begin(), o.end(), [&](int i, int j) { return w[i] < w[j]; });

  vector<ll> s(n, 1);
  ll res = 0;
  for (int v : o) {
    vector<ll> dp(w[v], 0);
    for (int nv : graph[v]) {
      for (int i = w[v] - w[nv] - 1; i >= 0; --i) {
        ChangeMax(dp[i + w[nv]], dp[i] + s[nv]);
      }
    }
    s[v] += *max_element(dp.begin(), dp.end());
    res += a[v] * s[v];
  }

  cout << res << endl;
  return 0;
}