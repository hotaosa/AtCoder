#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s, k;
    cin >> n >> s >> k;
    int g = gcd(n, gcd(s, k));
    n /= g;
    s /= g;
    k /= g;
    g = gcd(n, k);
    if (g != 1) cout << "-1" << endl;
    else {
      s = n - s;      
      mint::set_mod(n);
      cout << (mint(s) / mint(k)).val() << endl;
    }
  }
  return 0;
}
