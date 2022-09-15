#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  a.push_back(k + a[0]);

  int res = k;
  for (int i = 1; i <= n; ++i) res = min(res, k - (a[i] - a[i - 1]));
  cout << res << endl;  
  return 0;
}
