#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;

  int cnt = 0;
  vector<vector<bool> > is_black(h, vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      if (s[j] == '#') {
        is_black[i][j] = true;
        ++cnt;
      }
    }
  }

  int res = 0;
  for (int bit = 0; bit < (1 << h); ++bit) {
    int pc = __builtin_popcount(bit);
    if (pc > k) continue;
    int cur = cnt;
    vector<int> add(w, 0);
    for (int c = 0; c < w; ++c) {
      for (int r = 0; r < h; ++r) {
        if (!is_black[r][c]) {
          if (bit & (1 << r)) ++cur;
          else ++add[c];
        }
      }
    }
    sort(add.rbegin(), add.rend());
    for (int i = 0; pc + i < k; ++i) cur += add[i];
    res = max(res, cur);
  }

  cout << res << endl;  
  return 0;
}
