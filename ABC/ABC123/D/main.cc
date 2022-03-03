#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<long long> a(x), b(y), c(z);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;
  for (auto &p : c) cin >> p;

  vector<long long> bc(y * z);
  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < z; ++j) {
      bc[i * z + j] = b[i] + c[j];
    }
  }
  sort(a.begin(), a.end(), greater<>());
  sort(bc.begin(), bc.end(), greater<>());

  vector<long long> res;
  for (int i = 0; i < min(k, x); ++i) {
    for (int j = 0; j < min(k, y * z); ++j) {
      res.push_back(a[i] + bc[j]);
    }
  }
  sort(res.begin(), res.end(), greater<>());
  for (int i = 0; i < k; ++i) cout << res[i] << endl;
  return 0;
}
