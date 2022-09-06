#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  const int SIZE = max(r1, max(c1, max(r2, c2))) * 2 + 2;
  vector<mint> fact(SIZE), finv(SIZE);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < SIZE; ++i) fact[i] = fact[i - 1] * i;
  finv[SIZE - 1] = fact[SIZE - 1].inv();
  for (int i = SIZE - 1; i > 2; --i) finv[i - 1] = finv[i] * i;

  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };

  auto func = [&](int r, int c) -> mint {
    mint ret = 0;
    for (int i = 0; i <= r; ++i) ret += binom(i + c + 1, i + 1);
    return ret;
  };

  mint res = func(r2, c2) - func(r1 - 1, c2) - func(r2, c1 - 1) + func(r1 - 1, c1 - 1);
  cout << res.val() << endl;  
  return 0;
}
