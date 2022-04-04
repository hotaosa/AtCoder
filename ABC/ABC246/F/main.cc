#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, l;  
  cin >> n >> l;

  vector<int> vs(n, 0);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char c : s) vs[i] |= 1 << (c - 'a');
  }

  mint res = 0;
  for (int bit = 1; bit < (1 << n); ++bit) {
    int ch = (1 << 26) - 1, cnt = 0;
    for (int i = 0; i < n; ++i) if (bit & (1 << i)) { ch &= vs[i]; ++cnt; }
    int pc = __builtin_popcount(ch);    
    if (cnt & 1) res += mint(pc).pow(l);
    else res -= mint(pc).pow(l);
  }

  cout << res.val() << endl;
  return 0;
}
