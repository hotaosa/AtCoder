#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  
  vector<vector<int> > b(k);
  for (int i = 0; i < n; ++i) b[i % k].push_back(a[i]);
  for (int i = 0; i < k; ++i) sort(b[i].begin(), b[i].end());

  vector<int> c;
  for (int i = 0; i < n; ++i) c.push_back(b[i % k][i / k]);

  for (int i = 1; i < n; ++i) if (c[i] < c[i - 1]) { cout << "No" << endl; return 0; }
  cout << "Yes" << endl;  
  return 0;
}
