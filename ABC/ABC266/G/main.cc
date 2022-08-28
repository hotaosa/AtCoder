#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int r, g, b, k;
  cin >> r >> g >> b >> k;

  const int SIZE = r + g + b + 1;
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

  mint res = binom(b + g, b) * binom(g, k) * multi(b + k + 1, r - k);
  cout << res.val() << endl;
  return 0;
}
