#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

using vec = vector<mint>;
using mat = vector<vec>;

mat mat_mul(const mat &a, const mat &b) {
  mat ret(a.size(), vec(b[0].size()));
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int k = 0; k < (int)b.size(); ++k) {
      for (int j = 0; j < (int)b[0].size(); ++j) {
        ret[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return ret;
}

mat mat_pow(mat a, long long n) {
  mat ret(a.size(), vec(a.size()));
  for (int i = 0; i < (int)a.size(); ++i) ret[i][i] = 1;
  while (n > 0) {
    if (n & 1) ret = mat_mul(ret, a);
    a = mat_mul(a, a);
    n >>= 1;
  }
  return ret;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  mat res(n, vec(1));
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    res[i][0] = a;
  }

  vector<int> cnt(n, 0);
  vector<vector<bool> > exist_edge(n, vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    ++cnt[--u];
    ++cnt[--v];
    exist_edge[u][v] = exist_edge[v][u] = true;
  }

  mat ma(n, vec(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j == i) ma[i][j] = mint(1) - mint(cnt[i]) / mint(2 * m);
      else if (exist_edge[i][j]) ma[j][i] = mint(1) / mint(2 * m);
    }
  }

  res = mat_mul(mat_pow(ma, k), res);
  for (int i = 0; i < n; ++i) cout << res[i][0].val() << endl;
  return 0;
}
