#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int q;
  cin >> q;

  set<int> se;
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      se.insert(x);
      se.insert(-x);
    } else {
      if (se.size() == 0) {
        cout << -1 << endl;
      } else {
        int res = 1 << 30;
        auto p = se.lower_bound(x);
        if (p != se.end()) res = min(res, *p - x);
        if (p != se.begin()) res = min(res, x - *(--p));
        cout << res << endl;
      }      
    }
  }
  
  return 0;
}
