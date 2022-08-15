#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  
  vector<int> deg(n, 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    ++deg[--u];
    ++deg[--v];
  }

  int cnt_odd = 0, cnt_even = 0;
  for (int i = 0; i < n; ++i) ++(deg[i] & 1 ? cnt_odd : cnt_even);

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

  mint res = 0;
  for (int i = 0; i <= k; i += 2) {
    res += binom(cnt_odd, i) * binom(cnt_even, k - i);
  }
  cout << res.val() << endl;
  return 0;
}
