#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
//
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> nodes{0}, x(m), y(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
    nodes.emplace_back(--x[i]);
    nodes.emplace_back(--y[i]);
  }
  sort(begin(nodes), end(nodes));
  nodes.erase(unique(begin(nodes), end(nodes)), end(nodes));

  int siz = size(nodes);
  map<int, int> mp;
  for (int i = 0; i < siz; ++i) mp[nodes[i]] = i;

  vector<vector<pair<int, int>>> g(siz);
  for (int i = 0; i < m; ++i) {
    g[mp[x[i]]].emplace_back(mp[y[i]], 1);
  }
  for (int i = 0; i < siz - 1; ++i) {
    g[i].emplace_back(i + 1, nodes[i + 1] - nodes[i]);
  }
  g.back().emplace_back(0, n - nodes.back() + nodes[0]);

  vector dp(k + 1, vector<mint>(siz, 0));
  dp[0][0] = 1;

  mint res{0};
  for (int c = 0; c < k; ++c) {
    for (int v = 0; v < siz; ++v) {
      if (dp[c][v] == 0) continue;
      for (auto [u, w] : g[v]) {
        if (c + w <= k) {
          dp[c + w][u] += dp[c][v];
        } else {
          res += dp[c][v];
        }
      }
    }
  }
  res += accumulate(begin(dp.back()), end(dp.back()), mint{0});
  cout << res.val() << endl;
  return 0;
}
