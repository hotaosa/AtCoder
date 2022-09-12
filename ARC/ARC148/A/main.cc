#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  sort(a.begin(), a.end());

  int g = 0;
  for (int i = 1; i < n; ++i) g = __gcd(g, a[i] - a[i - 1]);
  cout << (g == 1 ? 2 : 1) << endl;  
  return 0;
}
