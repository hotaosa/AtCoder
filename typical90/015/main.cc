#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  cin >> n;

  const int SIZE = n + 1;
  vector<mint> fact(SIZE), finv(SIZE);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < SIZE; ++i) fact[i] = fact[i - 1] * i;
  finv[SIZE - 1] = fact[SIZE - 1].inv();
  for (int i = SIZE - 1; i > 2; --i) finv[i - 1] = finv[i] * i;
  
  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };

  auto query = [&](int k) -> int {
    mint res = 0;
    for (int i = 1; i <= n / k + 1; ++i) res += binom(n - (k - 1) * (i - 1), i);
    return res.val();
  };

  for (int i = 1; i <= n; ++i) cout << query(i) << endl;
  return 0;
}
