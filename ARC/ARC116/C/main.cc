#include <iostream>
#include <vector>
#include <map>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;

map<int, int> prime_factor(int x) {
  map<int, int> ret;
  for (int i = 2; i * i <= x; ++i) {
    while (x % i == 0) {
      ++ret[i];
      x /= i;
    }
  }
  if (x != 1) ++ret[x];
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;

  const int SIZE = n + m + 1;
  vector<mint> fact(SIZE), finv(SIZE);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < SIZE; ++i) fact[i] = fact[i - 1] * i;
  finv[SIZE - 1] = fact[SIZE - 1].inv();
  for (int i = SIZE - 1; i > 2; --i) finv[i - 1] = finv[i] * i;
  
  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };
  auto multi = [&](int n, int r) -> mint {
    return binom(n + r - 1, r);
  };

  mint res = 0;
  for (int i = 1; i <= m; ++i) {
    auto pf = prime_factor(i);
    mint add = 1;
    for (auto m : pf) add *= multi(n, m.second);
    res += add;
  }
  cout << res.val() << endl;
  return 0;
}