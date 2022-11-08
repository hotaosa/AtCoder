#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  long long res = 0;
  for (int l = 1; l <= n; ++l) {
    int r = upper_bound(a.begin(), a.end(), a[l - 1] + k) - a.begin();
    res += r - l;
  }

  cout << res << endl;  
  return 0;
}
