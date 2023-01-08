#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

int main() {
  int n, m;
  cin >> n >> m;

  mint::set_mod(m);

  vector<mint> pow(n, 1), perm(n, 1);
  for (int i = 1; i < n; ++i) {
    pow[i] = pow[i - 1] * n;
    perm[i] = perm[i - 1] * (n - i);
  }
  
  mint res = 0;
  for (int l = 1; l <= n; ++l) {
    res += perm[l - 1] * pow[n - l] * ((long long)l * (l - 1) / 2);
  }
  res *= n;

  cout << res.val() << endl;
  return 0;
}
