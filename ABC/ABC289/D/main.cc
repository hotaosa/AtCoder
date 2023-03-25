#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<bool> s(100000, false);
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int b;
    cin >> b;
    s[b] = true;
  }

  int x;
  cin >> x;
  vector<bool> p(x + 1, false);
  p[0] = true;

  for (int i = 0; i < x; ++i) {
    if (!p[i] || s[i]) continue;
    for (int d : a) {
      if (i + d <= x) p[i + d] = true;
    }
  }

  cout << (p[x] ? "Yes" : "No" ) << endl;  
  return 0;
}
