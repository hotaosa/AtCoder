#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

mint binom(int n, int r) {
  mint ret = 1;
  for (int i = 0; i < r; ++i) ret *= (n - i);
  for (int i = 1; i <= r; ++i) ret /= (i);
  return ret;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  mint res = mint(2).pow(n) - 1;
  res -= binom(n, a);
  res -= binom(n, b);
  cout << res.val() << endl;  
  return 0;
}
