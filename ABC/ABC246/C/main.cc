#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k, x;
  cin >> n >> k >> x;

  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  for (int i = 0; i < n && k > 0; ++i) {
    long long use = min(k, a[i] / x);
    a[i] -= use * x;
    k -= use;
  }
  
  sort(a.begin(), a.end(), greater<>());
  long long res = 0;
  for (int i = 0; i < n; ++i, --k) {
    if (k <= 0) res += a[i];
  }
  cout << res << endl;    
  return 0;
}
