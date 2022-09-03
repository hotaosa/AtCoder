#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;

  long long d = 0;
  for (int i = 0; i < n; ++i) d += abs(a[i] - b[i]);
  cout << (d <= k && (k - d) % 2 == 0 ? "Yes" : "No" ) << endl;  
  return 0;
}
