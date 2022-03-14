#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, bool> ma;
  vector<int> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) { cin >> p; ma[p] = true; }

  int res1 = 0, res2 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) ++res1;
    else if (ma[a[i]]) ++res2;
  }
  cout << res1 << endl << res2 << endl;
  return 0;
}
