#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int x, y;
  cin >> x >> y;

  const int SIZE = max(x, y) * 2;
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
  for (int i = 0; i <= x; ++i) {
    if ((x - i) & 1) continue;
    int j = (x - i) / 2;
    if (2 * i + j != y) continue;
    res += binom(i + j, i);
  }

  cout << res.val() << endl;  
  return 0;
}