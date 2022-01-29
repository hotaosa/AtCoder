#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  sort(a.begin(), a.end());

  vector<mint> fact(n + 1), finv(n + 1);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < n + 1; ++i) fact[i] = fact[i - 1] * i;
  finv[n + 1 - 1] = fact[n + 1 - 1].inv();
  for (int i = n + 1 - 1; i > 2; --i) finv[i - 1] = finv[i] * i;
  
  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };

  mint res = 0;
  for (int i = k - 1; i < n; ++i) res += mint(a[i]) * binom(i, k - 1);
  reverse(a.begin(), a.end());
  for (int i = k - 1; i < n; ++i) res -= mint(a[i]) * binom(i, k - 1);
  cout << res.val() << endl;
  return 0;
}
