#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  long long t;
  cin >> n >> m >> t;
  vector<long long> a(n - 1);
  for (auto &p : a) cin >> p;
  vector<long long> bonus(n - 1, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    bonus[--x] = y;
  }

  int pos = 0;
  while (pos < n - 1) {
    t += bonus[pos];
    t -= a[pos];
    if (t <= 0) {
      cout << "No" << endl;
      return 0;
    }
    ++pos;
  }
  cout << (t > 0 ? "Yes" : "No" ) << endl;
  return 0;
}
