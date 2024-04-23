#include <iostream>
#include <numeric>
#include <vector>
//
#include <atcoder/dsu>

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> deg(n, 0);
  atcoder::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    uf.merge(--u, --v);
    ++deg[u];
    ++deg[v];
  }

  ll res = 0;
  for (const auto &g : uf.groups()) {
    ll siz = size(g);
    ll cnt = accumulate(begin(g), end(g), 0LL,
                        [&deg](ll acc, int i) { return acc + deg[i]; });
    res += (siz * (siz - 1) - cnt) >> 1;
  }

  cout << res << endl;
  return 0;
}