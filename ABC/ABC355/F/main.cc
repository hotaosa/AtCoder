#include <iostream>
#include <vector>
//
#include <atcoder/dsu>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector uf(11, atcoder::dsu(n));
  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    res += c;

    for (int j = c; j <= 10; ++j) {
      uf[j].merge(a, b);
    }
  }

  while (q--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    for (int i = w; i <= 10; ++i) {
      if (!uf[i].same(u, v)) {
        uf[i].merge(u, v);
        --res;
      }
    }
    cout << res << endl;
  }

  return 0;
}
