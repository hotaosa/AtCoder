#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<long long> > vd(n);
  for (int i = 0; i < n; ++i) {
    int t;
    long long d;
    cin >> t >> d;
    vd[--t].push_back(d);
  }

  for (auto &v : vd) sort(v.rbegin(), v.rend());
  vector<long long> mx, others;
  for (int i = 0; i < n; ++i) {
    if (vd[i].empty()) continue;
    mx.push_back(vd[i][0]);
    for (int j = 1; j < (int)vd[i].size(); ++j) others.push_back(vd[i][j]);
  }
  sort(mx.rbegin(), mx.rend());  
  sort(others.rbegin(), others.rend());

  vector<long long> sum_a(mx.size() + 1, 0), sum_b(others.size() + 1, 0);
  for (int i = 0; i < (int)mx.size(); ++i) sum_a[i + 1] = sum_a[i] + mx[i];
  for (int i = 0; i < (int)others.size(); ++i) sum_b[i + 1] = sum_b[i] + others[i];
  
  long long res = 0;
  for (int i = 1; i <= k; ++i) {
    if (i >= (int)sum_a.size()) continue;
    if (k - i >= (int)sum_b.size()) continue;
    long long cur = (long long)i * i + sum_a[i] + sum_b[k - i];
    res = max(res, cur);
  }  
  cout << res << endl;  
  return 0;
}
