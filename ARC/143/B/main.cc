#include <iostream>
#include <vector>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  cin >> n;

  const int SIZE = n * n + 1;
  vector<mint> fact(SIZE), finv(SIZE);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < SIZE; ++i) fact[i] = fact[i - 1] * i;
  finv[SIZE - 1] = fact[SIZE - 1].inv();
  for (int i = SIZE - 1; i > 2; --i) finv[i - 1] = finv[i] * i;
  
  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };

  mint res = fact[n * n];
  for (int i = 1; i <= n * n; ++i) {
    res -= binom(n * n - i, n - 1) * binom(i - 1, n - 1) * fact[n - 1] * fact[n - 1] * n * n * fact[n * n - 2 * n + 1];
  }
  cout << res.val() << endl;
  return 0;  
}