#include <iostream>
#include <vector>

using vec = std::vector<long long>;
using mat = std::vector<vec>;

constexpr long long MOD = 1000000007LL;

mat mul(mat a, mat b) {
  mat ret(a.size(), vec(b[0].size(), 0LL));
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int j = 0; j < (int)b[0].size(); ++j) {
      for (int k = 0; k < (int)a[0].size(); ++k) {
        ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  return ret;
}

mat pow(mat a, long long n) {
  mat ret(a.size(), vec(a.size(), 0LL));
  for (int i = 0; i < (int)a.size(); ++i) ret[i][i] = 1LL;
  while (n) {
    if (n & 1LL) ret = mul(ret, a);
    a = mul(a, a);
    n >>= 1;
  }
  return ret;
}

int main() {
  long long n;
  int b, k;
  std::cin >> n >> b >> k;

  std::vector<int> usable(k);
  for (int i = 0; i < k; ++i) std::cin >> usable[i];

  mat m(b, vec(b, 0LL));

  for (int i = 0; i < b; ++i) {
    for (int nx : usable) {
      ++m[i][(i * 10 + nx) % b];
    }
  }

  mat v(1, vec(b, 0LL));
  v[0][0] = 1LL;
  mat res = mul(v, pow(m, n));
  std::cout << res[0][0] << std::endl;
  return 0;
}
