#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bitset<300> > button(n);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    while (t--) {
      int a;
      cin >> a;
      button[i].set(--a);
    }
  }

  bitset<300> s;
  for (int i = 0; i < m; ++i) {
    int si;
    cin >> si;
    if (si) s.set(i);
  }

  int pos = 0;
  for (int i = 0; i < m; ++i) {    
    int p = pos;
    while (p < n && !button[p][i]) ++p;
    if (p == n) continue;
    swap(button[p], button[pos]);
    for (int j = 0; j < n; ++j) {
      if (j != pos && button[j][i]) button[j] ^= button[pos];
    }
    if (s[i]) s ^= button[pos];
    ++pos;
  }

  mint res = 0;
  if (s.none()) {
    int cnt_zero = 0;
    for (int i = 0; i < n; ++i) if (button[i].none()) ++cnt_zero;
    res = mint(2).pow(cnt_zero);
  }
  cout << res.val() << endl;
  return 0;
}
