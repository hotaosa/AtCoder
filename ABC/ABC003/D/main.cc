#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int r, c, x, y, d, l;
  cin >> r >> c >> x >> y >> d >> l;

  constexpr int SIZE = 901;
  vector<mint> fact(SIZE), finv(SIZE);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < SIZE; ++i) fact[i] = fact[i - 1] * i;
  finv[SIZE - 1] = fact[SIZE - 1].inv();
  for (int i = SIZE - 1; i > 2; --i) finv[i - 1] = finv[i] * i;  
  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };
  auto f = [&](int a, int b) -> mint {
    if (a <= 0 || b <= 0 || a * b < d + l) return 0;
    return binom(a * b, d + l) * binom(d + l, d);
  };
  
  mint res = f(x, y) - (f(x - 1, y) * 2 + f(x, y - 1) * 2) + (f(x - 2, y) + f(x, y - 2) + f(x - 1, y - 1) * 4) - (f(x - 2, y - 1) * 2 + f(x - 1, y - 2) * 2) + f(x - 2, y - 2);  
  res *= (r - x + 1) * (c - y + 1);
  cout << res.val() << endl;
  return 0;
}
