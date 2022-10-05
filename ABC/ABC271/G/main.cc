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
  int x, y;
  string s;
  cin >> n >> x >> y >> s;
  mint px = mint(x) / 100;
  mint py = mint(y) / 100;

  mat m(24, vec(24, 0));  
  for (int i = 0; i < 24; ++i) {
    mint pt = 1, sum = 0;    
    for (int j = (i + 1) % 24; true; j = (j + 1) % 24) {
      m[j][i] = pt * (s[j] == 'T' ? px : py);
      sum += m[j][i];
      if (j == i) break;
      pt *= (s[j] == 'T' ? 1 - px : 1 - py);
    }
    for (int j = 0; j < 24; ++j) m[j][i] /= sum;
  }

  mat v(24, vec(1, 0));
  v[23][0] = 1;

  v = mat_mul(mat_pow(m, n), v);
  mint res = 0;
  for (int i = 0; i < 24; ++i) if (s[i] == 'A') res += v[i][0];  
  cout << res.val() << endl;
  return 0;
}
