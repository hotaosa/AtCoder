#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    graph[--u].emplace_back(--v, -c);
    graph[v].emplace_back(u, c);
  }

  map<int, vector<pair<int, int>>> mp;
  vector<int> leader(n, -1), dist(n, 0);

  auto DFS1 = [&](auto DFS1, int v) -> void {
    mp[leader[v]].emplace_back(dist[v], v);
    for (auto [nv, d] : graph[v]) {
      if (leader[nv] != -1) continue;
      leader[nv] = leader[v];
      dist[nv] = dist[v] + d;
      DFS1(DFS1, nv);
    }
  };

  for (int i = 0; i < n; ++i) {
    if (leader[i] == -1) {
      leader[i] = i;
      DFS1(DFS1, i);
    }
  }

  vector<pair<int, int>> groups;
  for (const auto &[l, vp] : mp) {
    auto [o, v] = *min_element(begin(vp), end(vp));
    int b = 0;
    for (auto [d, _] : vp) {
      b |= (1 << (d - o));
    }
    groups.emplace_back(v, b);
  }

  vector<int> res(n, -1);
  int full = (1 << n) - 1;

  auto DFS2 = [&](auto DFS2, int v) -> void {
    for (auto [nv, d] : graph[v]) {
      if (res[nv] != -1) continue;
      res[nv] = res[v] + d;
      DFS2(DFS2, nv);
    }
  };

  for (auto [v, vb] : groups) {
    vector<bool> dp(1 << n, false);
    dp[0] = true;
    for (auto [u, ub] : groups) {
      if (u == v) continue;
      for (int b = full; b >= 0; --b) {
        if (!dp[b]) continue;
        for (int s = 0; ub << s <= full; ++s) {
          if (b & (ub << s)) continue;
          dp[b | (ub << s)] = true;
        }
      }
    }
    vector<int> cand;
    for (int s = 0; vb << s <= full; ++s) {
      int target = full & ~(vb << s);
      if (dp[target]) {
        cand.emplace_back(s);
      }
    }
    assert(!cand.empty());
    if (size(cand) == 1) {
      res[v] = cand[0] + 1;
      DFS2(DFS2, v);
    }
  }

  for (auto r : res) {
    cout << r << " ";
  }
  cout << endl;

  return 0;
}