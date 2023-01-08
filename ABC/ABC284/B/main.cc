#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, res = 0;
    cin >> n;
    while (n--) {
      int a;
      cin >> a;
      res += a & 1;
    }
    cout << res << endl;
  }
  
  return 0;
}
