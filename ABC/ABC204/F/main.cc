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
  int h;
  long long w;
  cin >> h >> w;
  int siz = 1 << h;

  mat v(siz, vec(1, 0));
  for (int bit = 0; bit < siz; ++bit) {
    bool possible = true;
    int len = 0;
    for (int i = 0; i < h; ++i) {
      if (bit & (1 << i)) ++len;
      else { possible &= !(len & 1); len = 0; }
    }
    possible &= !(len & 1);
    if (possible) ++v[bit][0];
  }
  
  mat m(siz, vec(siz, 0));
  for (int i = 0; i < siz; ++i) {
    for (int j = 0; j < siz; ++j) {
      for (int k = 0; k < siz; ++k) {
        bool possible = true;
        for (int l = 0; l < h; ++l) {
          if (i & (1 << l) && k & (1 << l)) possible = false;
          if (!(j & (1 << l)) && k & (1 << l)) possible = false;
        }
        if (possible && v[j - k][0] == 0) possible = false;
        if (possible) ++m[j][i];
      }
    }
  }
  
  auto vm = mat_mul(mat_pow(m, w - 1), v);  
  mint res = 0;
  for (int i = 0; i < siz; ++i) res += vm[i][0];
  cout << res.val() << endl;
  return 0;
}
