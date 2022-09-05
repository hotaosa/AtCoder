#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

map<long long, int> prime_factorization(long long num) {
  map<long long, int> ret;
  for (long long i = 2; i * i <= num; ++i) {
    while (num % i == 0) {
      ++ret[i];
      num /= i;
    }
  }
  if (num != 1) ++ret[num];
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  auto mp = prime_factorization(m);
  int cnt = 0;
  for (auto m : mp) cnt += m.second;
  const int SIZE = max(n, cnt) * 2;

  vector<mint> fact(SIZE), finv(SIZE);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < SIZE; ++i) fact[i] = fact[i - 1] * i;
  finv[SIZE - 1] = fact[SIZE - 1].inv();
  for (int i = SIZE - 1; i > 2; --i) finv[i - 1] = finv[i] * i;
  
  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };  
  
  mint res = 1;
  for (auto m : mp) {
    res *= binom(n + m.second - 1, m.second);
  }
  cout << res.val() << endl;
  return 0;
}
