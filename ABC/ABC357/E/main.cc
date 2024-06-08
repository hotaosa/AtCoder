#include <iostream>
#include <numeric>
#include <set>
//
#include <atcoder/scc>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
    --e;
  }

  atcoder::scc_graph graph(n);
  for (int i = 0; i < n; ++i) {
    graph.add_edge(i, a[i]);
  }
  const auto scc = graph.scc();

  ll res = 0;

  vector<int> b(n, -1);  // belonging
  int siz = size(scc);
  vector<ll> cnt(siz, 0);
  for (int i = siz - 1; i >= 0; --i) {
    cnt[i] = size(scc[i]);
    set<int> se = {i};
    for (int v : scc[i]) {
      b[v] = i;
      if (b[a[v]] != -1) {
        se.insert(b[a[v]]);
      }
    }
    cnt[i] = accumulate(begin(se), end(se), 0LL,
                        [&cnt](ll acc, int j) { return acc + cnt[j]; });
    res += size(scc[i]) * cnt[i];
  }

  cout << res << endl;
  return 0;
}