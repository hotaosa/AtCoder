#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

void ChangeMin(ll &a, ll b) { a = min(a, b); }

int main() {
  int n, m;
  cin >> n >> m;
  vector nodes(m, vector<int>(2));
  vector<ll> t(m);

  vector dist(n, vector<ll>(n, INF));
  for (int i = 0; i < n; ++i) dist[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    cin >> nodes[i][0] >> nodes[i][1] >> t[i];
    --nodes[i][0];
    --nodes[i][1];
    ChangeMin(dist[nodes[i][0]][nodes[i][1]], t[i]);
    ChangeMin(dist[nodes[i][1]][nodes[i][0]], t[i]);
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ChangeMin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  auto Solve = [&](vector<int> edges) -> ll {
    ll res = INF;
    do {
      for (int b = 0; b < (1 << size(edges)); ++b) {
        int node = 0;
        ll cur = 0;
        for (int i = 0; i < (int)size(edges); ++i) {
          int u = nodes[edges[i]][b >> i & 1];
          int v = nodes[edges[i]][(b >> i & 1) ^ 1];
          cur += dist[node][u] + t[edges[i]];
          node = v;
        }
        cur += dist[node].back();
        ChangeMin(res, cur);
      }
    } while (next_permutation(begin(edges), end(edges)));
    return res;
  };

  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    vector<int> edges(k);
    for (auto &e : edges) {
      cin >> e;
      --e;
    }
    cout << Solve(edges) << endl;
  }

  return 0;
}
