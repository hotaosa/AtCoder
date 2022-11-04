#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n), c(n), d(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;
  for (auto &p : c) cin >> p;
  for (auto &p : d) cin >> p;

  set<int> se;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) se.insert(c[i] + d[j]);

  bool possible = false;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) possible |= se.count(k - a[i] - b[j]);
  
  cout << (possible ? "Yes" : "No" ) << endl;  
  return 0;
}
