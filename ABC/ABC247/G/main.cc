#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 10000000000LL;

int main() {
  int n;
  cin >> n;
  vector<vector<long long> > cost(150, vector<long long>(150, INF));
  for (int i = 0; i < n; ++i) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    --a;
    --b;
    cost[a][b] = min(cost[a][b], INF - c);
  }

  atcoder::mcf_graph<int, long long> graph(302);
  constexpr int s = 300, t = 301;

  for (int i = 0; i < 150; ++i) {
    graph.add_edge(s, i, 1, 0);
    graph.add_edge(150 + i, t, 1, 0);
    for (int j = 0; j < 150; ++j) if (cost[i][j] < INF) graph.add_edge(i, 150 + j, 1, cost[i][j]);
  }

  auto slope = graph.slope(s, t);
  vector<long long> res;

  for (int i = 1; i <= slope.back().first; ++i) {
    auto p = lower_bound(slope.begin(), slope.end(), make_pair(i, 0LL));
    if (p->first == i) res.push_back(INF * i - p->second);
    else {
      auto pl = p;
      --pl;
      res.push_back(INF * i - (p->second - pl->second) / (p->first - pl->first) * (i - pl->first) + pl->second);
    }
  }

  cout << res.size() << endl;
  for (auto &p : res) cout << p << endl;
  return 0;
}
