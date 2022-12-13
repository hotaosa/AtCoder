#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &p : a) { cin >> p; --p; }

  vector<vector<pair<int, int> > > mv(n);
  for (int i = 0; i < m; ++i) {
    mv[a[i]].emplace_back(i + 1, a[i] + 1);
    mv[a[i] + 1].emplace_back(i + 1, a[i]);
  }

  vector<map<int, int> > memo(m);
  auto solve = [&](auto solve, int t, int v) -> int {
    if (t == m) return v + 1;
    if (memo[t].count(v)) return memo[t][v];
    auto p = lower_bound(mv[v].begin(), mv[v].end(), make_pair(t + 1, 0));
    if (p == mv[v].end()) return memo[t][v] = v + 1;
    return memo[t][v] = solve(solve, p->first, p->second);
  };

  int pos = 0;
  for (int i = 0; i < m; ++i) {
    cout << solve(solve, i + 1, pos) << endl;
    if (a[i] == pos) ++pos;
    else if (a[i] == pos - 1) --pos;
  }
  return 0;
}
