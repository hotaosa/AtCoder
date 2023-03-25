#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(m, 0);
  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    while (c--) {
      int a;
      cin >> a;
      v[i] |= 1 << --a;
    }
  }

  int res = 0;
  for (int b = 1; b < (1 << m); ++b) {
    int cur = 0;
    for (int i = 0; i < m; ++i) {
      if (b >> i & 1) cur |= v[i];
    }
    if (cur == (1 << n) - 1) ++res;
  }

  cout << res << endl;  
  return 0;
}
