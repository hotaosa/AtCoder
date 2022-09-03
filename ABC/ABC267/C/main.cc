#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;
  vector<long long> sum(n + 1, 0);
  for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i];

  long long cur = 0;
  for (int i = 0; i < m; ++i) cur += a[i] * (i + 1);
  long long res = cur;
  for (int i = m; i < n; ++i) {
    cur -= sum[i] - sum[i - m];
    cur += a[i] * m;
    res = max(res, cur);
  }

  cout << res << endl;  
  return 0;
}
