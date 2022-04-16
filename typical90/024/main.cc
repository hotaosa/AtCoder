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

  long long cnt = 0;  
  for (int i = 0; i < n; ++i) cnt += abs(a[i] - b[i]);

  cout << (cnt <= k && !((k - cnt) & 1) ? "Yes" : "No" ) << endl;
  return 0;
}
