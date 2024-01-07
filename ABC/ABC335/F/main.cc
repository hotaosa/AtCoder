#include <cmath>
#include <iostream>
#include <vector>

#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;
istream &operator>>(istream &is, mint &m) { long long in; is >> in; m = in; return is; }
ostream &operator<<(ostream &os, const mint &m) { os << m.val(); return os; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;

  const int siz(sqrt(n));
  vector<mint> dp1(n, 0);
  vector dp2(siz, vector<mint>(siz, 0));
  dp1[0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < siz; ++j) {
      dp1[i] += dp2[j][i % j];
    }
    if (a[i] >= siz) {
      for (int j = i + a[i]; j < n; j += a[i]) {
        dp1[j] += dp1[i];
      }
    } else {
      dp2[a[i]][i % a[i]] += dp1[i];
    }
  }

  cout << accumulate(dp1.begin(), dp1.end(), mint(0)) << endl;
  return 0;
}