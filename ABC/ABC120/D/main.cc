#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> u(m), v(m);
  for (int i = 0; i < m; ++i) { cin >> u[i] >> v[i]; --u[i]; --v[i]; }

  atcoder::dsu uf(n);
  long long cur = n;
  cur *= n - 1;
  cur /= 2;
  vector<long long> res(m);
  for (int i = m - 1; i >= 0; --i) {
    res[i] = cur;
    if (!uf.same(u[i], v[i])) {
      cur -= uf.size(u[i]) * uf.size(v[i]);
      uf.merge(u[i], v[i]);
    }
  }
  for (auto &p : res) cout << p << endl;
  return 0;
}
