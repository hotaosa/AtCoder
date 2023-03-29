#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a;
  int z = 0;
  for (int i = 0; i < n; ++i) {
    int ai;
    cin >> ai;
    if (ai == 0) ++z;
    else a.push_back(ai);
  }
  sort(a.begin(), a.end());

  vector binom(z + 1, vector<mint>(z + 1));
  binom[0][0] = 1;
  for (int i = 0; i < z; ++i) {
    for (int j = 0; j <= z; ++j) {
      binom[i + 1][j] += binom[i][j];
      if (j < z) binom[i + 1][j + 1] += binom[i][j];
    }
  }

  auto Count = [&](int ub) -> int {
    return lower_bound(a.begin(), a.end(), ub) - a.begin();
  };

  mint res = 0;
  for (int x = 1; x <= m; ++x) {
    int cnt = Count(x);
    for (int c = 0; c < min(z + 1, k - cnt); ++c) {
      res += binom[z][c] * mint(x - 1).pow(c) * mint(m - x + 1).pow(z - c);
    }
  }
  res /= mint(m).pow(z);

  cout << res.val() << endl;
  return 0;
}
