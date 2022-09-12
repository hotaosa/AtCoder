#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;

  bool flip = false;
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;    
    if (t == 1) {
      --a; --b;
      if (flip) {
        a = (a < n ? a + n : a - n);
        b = (b < n ? b + n : b - n);
      }
      swap(s[a], s[b]);
    } else {
      flip = !flip;
    }
  }

  if (flip) s = s.substr(n, n) + s.substr(0, n);
  cout << s << endl;
  return 0;
}
