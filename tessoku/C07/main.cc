#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (auto &p : c) cin >> p;
  sort(c.begin(), c.end());
  for (int i = 1; i < n; ++i) c[i] += c[i - 1];

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << upper_bound(c.begin(), c.end(), x) - c.begin() << endl;
  }
  
  return 0;
}
