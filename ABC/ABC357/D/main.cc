#include <iostream>
//
#include <atcoder/modint>

using namespace std;
using ll = long long;
// clang-format off
using mint = atcoder::modint998244353;
istream &operator>>(istream &is, mint &m) { ll in; is >> in; m = in; return is; }
ostream &operator<<(ostream &os, const mint &m) { os << m.val(); return os; }
// clang-format on

int main() {
  ll n;
  cin >> n;

  int k = size(to_string(n));
  mint p = mint(10).pow(k);
  mint res = n * (p.pow(n) - 1) / (p - 1);
  cout << res << endl;

  return 0;
}