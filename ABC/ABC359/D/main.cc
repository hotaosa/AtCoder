#include <iostream>
#include <numeric>
#include <vector>
//
#include <atcoder/modint>

using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
istream &operator>>(istream &is, mint &m) {
  ll in;
  is >> in;
  m = in;
  return is;
}
ostream &operator<<(ostream &os, const mint &m) {
  os << m.val();
  return os;
}

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> v(n, -1);
  for (int i = 0; i < n; ++i) {
    if (s[i] != '?') {
      v[i] = s[i] == 'A' ? 0 : 1;
    }
  }

  const int siz = 1 << k;
  const int mask = siz - 1;

  vector dp(n + 1, vector<mint>(siz, 0));
  dp[0][0] = 1;

  auto IsGood = [k](int b) -> bool {
    int rb = 0;
    for (int i = 0; i < k; ++i) {
      rb = (rb << 1) | (b >> i & 1);
    }
    return rb != b;
  };

  for (int i = 0; i < n; ++i) {
    for (int b = 0; b < siz; ++b) {
      for (int c = 0; c < 2; ++c) {
        if (v[i] != -1 && v[i] != c) continue;
        int nb = (b << 1 | c) & mask;
        if (i + 1 < k || IsGood(nb)) {
          dp[i + 1][nb] += dp[i][b];
        }
      }
    }
  }

  cout << accumulate(begin(dp.back()), end(dp.back()), mint(0)) << endl;
  return 0;
}
