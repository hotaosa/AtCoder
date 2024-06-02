#include <iostream>
//
#include <atcoder/modint>

using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;
ostream &operator<<(ostream &os, const mint &m) {
  os << m.val();
  return os;
}

int main() {
  ll n, m;
  cin >> n >> m;

  auto Func = [&](int b) -> mint {
    mint ret = (n >> (b + 1) << b);
    if (n >> b & 1) {
      ret += (n & ((1LL << b) - 1)) + 1;
    }
    return ret;
  };

  mint res = 0;
  for (int b = 0; b < 60; ++b) {
    if (m >> b & 1) {
      res += Func(b);
    }
  }
  cout << res << endl;
  return 0;
}