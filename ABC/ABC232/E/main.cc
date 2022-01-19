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
  int H, W, k, x1, y1, x2, y2;  
  cin >> H >> W >> k >> x1 >> y1 >> x2 >> y2;
  mint h = H, w = W;

  mat m(4, vector<mint>(4, 0));
  m[0][1] = w - 1;
  m[0][2] = h - 1;
  m[1][0] = 1;
  m[1][1] = w - 2;
  m[1][3] = h - 1;
  m[2][0] = 1;
  m[2][2] = h - 2;
  m[2][3] = w - 1;
  m[3][1] = 1;
  m[3][2] = 1;
  m[3][3] = h + w - 4;

  mat cnt(4, vector<mint>(1, 0));
  
  cnt[0][0] = 1;
  cnt = mat_mul(mat_pow(m, k), cnt);    
    
  int i = 3;
  if (x1 == x2 && y1 == y2) i = 0;
  else if (x1 == x2) i = 1;
  else if (y1 == y2) i = 2;

  cout << cnt[i][0].val() << endl;
  return 0;
}
