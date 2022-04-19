#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, m;
  cin >> n >> m;

  const int SIZE = m + 1;
  vector<mint> fact(SIZE), finv(SIZE);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < SIZE; ++i) fact[i] = fact[i - 1] * i;
  finv[SIZE - 1] = fact[SIZE - 1].inv();
  for (int i = SIZE - 1; i > 2; --i) finv[i - 1] = finv[i] * i;
  
  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };
  auto perm = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[n - r];
  };

  mint res = 0;
  for (int i = 0; i <= n; ++i) res += binom(n, i) * perm(m, i) * perm(m - i, n - i) * perm(m - i, n - i) * (i & 1 ? -1 : 1);
  cout << res.val() << endl;
  return 0;
}
