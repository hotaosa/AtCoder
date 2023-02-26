#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  vector<vector<long long> > v(k);
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    if (v[i % k].empty()) {
      v[i % k].push_back(a);
    } else {
      v[i % k].push_back(a + v[i % k].back());
    }
  }

  auto Judge = [&](int l, int r) -> bool {
    vector<long long> sum(k, 0);
    for (int i = 0; i < k; ++i) {
      int lb = l / k + (l % k > i ? 1 : 0);
      int ub = r / k - (r % k < i ? 1 : 0);
      sum[i] = v[i][ub] - (lb > 0 ? v[i][lb - 1] : 0);
    }
    for (int i = 1; i < k; ++i) {
      if (sum[i] != sum[i - 1]) return false;
    }
    return true;
  };

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (Judge(--l, --r) ? "Yes" : "No" ) << endl;
  }
  return 0;
}
