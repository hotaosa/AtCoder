#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int q;
  cin >> q;
  
  multiset<int> se;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      se.insert(x);
    } else if (t == 2) {
      int x, c;
      cin >> x >> c;
      while (c-- && se.find(x) != se.end()) se.erase(se.find(x));
    } else {
      cout << *se.rbegin() - *se.begin() << endl;
    }
  }
  return 0;
}
