#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) { cin >> x[i] >> y[i]; ++x[i]; }
  string s;
  cin >> s;
  map<int, int> l, r;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') r[y[i]] = x[i];
    else l[y[i]] = x[i];
  }
  
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') l[y[i]] = max(l[y[i]], x[i]);
    else r[y[i]] = min(r[y[i]], x[i]);
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L' && r[y[i]] != 0 && x[i] > r[y[i]]) { cout << "Yes" << endl; return 0; }
    if (s[i] == 'R' && l[y[i]] != 0 && x[i] < l[y[i]]) { cout << "Yes" << endl; return 0; }
  }  
  cout << "No" << endl;
  return 0;
}
