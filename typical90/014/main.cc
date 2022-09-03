#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  long long res = 0;
  for (int i = 0; i < n; ++i) res += abs(a[i] - b[i]);
  cout << res << endl;  
  return 0;
}
