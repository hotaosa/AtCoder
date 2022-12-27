#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  int q;
  cin >> q;
  while (q--) {
    int t, k;
    cin >> t >> k;
    if (t == 1) {
      int x;
      cin >> x;
      a[--k] = x;
    } else {
      cout << a[--k] << endl;
    }
  }
  
  return 0;
}
