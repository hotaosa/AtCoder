#include <iostream>
#include <vector>
//
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;

istream &operator>>(istream &is, mint &m) {
  long long in;
  is >> in;
  m = in;
  return is;
}

ostream &operator<<(ostream &os, const mint &m) {
  os << m.val();
  return os;
}

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &e : a) cin >> e;

  vector<mint> pow10(11);
  for (int i = 0; i <= 10; ++i) {
    pow10[i] = mint(10).pow(i);
  }

  mint res = 0;
  vector<mint> cnt(11, 0);
  for (int i = n - 1; i >= 0; --i) {
    auto x = mint(stoi(a[i]));
    res += x * i;
    for (int j = 1; j <= 10; ++j) {
      res += x * cnt[j] * pow10[j];
    }
    ++cnt[size(a[i])];
  }

  cout << res << endl;
  return 0;
}