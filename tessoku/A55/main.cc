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
    } else if (t == 2) {      
      se.erase(x);
    } else {
      auto p = se.lower_bound(x);
      cout << (p != se.end() ? *p : -1) << endl;
    }
  }
  
  return 0;
}
