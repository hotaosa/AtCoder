#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> l(n), r(n);
  for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
  sort(l.rbegin(), l.rend());
  sort(r.begin(), r.end());

  long long res = 0;
  for (int i = 0; i < n; ++i) res += max(0LL, l[i] - r[i]) * (n - 2 * i - 1);
  cout << res << endl;  
  return 0;
}
