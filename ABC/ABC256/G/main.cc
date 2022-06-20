#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

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
  long long n;
  int d;
  cin >> n >> d;

  const int SIZE = d + 1;
  vector<mint> fact(SIZE), finv(SIZE);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < SIZE; ++i) fact[i] = fact[i - 1] * i;
  finv[SIZE - 1] = fact[SIZE - 1].inv();
  for (int i = SIZE - 1; i > 2; --i) finv[i - 1] = finv[i] * i;
  
  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };
  
  mint res = 0;
  for (int i = 0; i <= d + 1; ++i) {
    mat m(4, vec(4));
    m[0][0] = binom(d - 1, i - 2);
    m[0][1] = binom(d - 1, i - 1);
    m[1][0] = binom(d - 1, i - 1);
    m[1][1] = binom(d - 1, i);
    m[2][2] = binom(d - 1, i - 2);
    m[2][3] = binom(d - 1, i - 1);
    m[3][2] = binom(d - 1, i - 1);
    m[3][3] = binom(d - 1, i);    

    mat v(1, vec(4));
    v[0][0] = binom(d - 1, i - 2);
    v[0][1] = v[0][2] = binom(d - 1, i - 1);
    v[0][3] = binom(d - 1, i);
    
    auto vv = mat_mul(v, mat_pow(m, n - 1));    
    res += vv[0][0] + vv[0][3];    
  }
  cout << res.val() << endl;
  return 0;
}
