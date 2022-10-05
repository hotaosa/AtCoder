#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

int modlog(mint x, mint y) {
  int m = sqrt(mint::mod()) + 1;
  unordered_map<unsigned int, int> baby;
  mint xb = y;
  for (int b = 0; b < m; ++b, xb *= x) baby[xb.val()] = b;
  mint xm = x.pow(m);
  mint xam = xm;
  for (int a = 1; a <= m; ++a, xam *= xm) {
    if (baby.count(xam.val())) return a * m - baby[xam.val()];
  }
  return -1;
}

int solve(int p, int a, int b, int s, int g) {
  mint::set_mod(p);
  if (s == g) return 0;
  if (a == 0) return (b == g ? 1 : -1);
  if (a == 1) return (__gcd(b, p) == 1 ? ((g - s) / mint(b)).val() : -1);
  mint div = s + b / mint(a - 1);
  if (div == 0) return -1;
  return modlog(a, (g + b / mint(a - 1)) / div);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int p, a, b, s, g;    
    cin >> p >> a >> b >> s >> g;
    cout << solve(p, a, b, s, g) << endl;    
  }
  return 0;
}
