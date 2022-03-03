#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<bool> > is_white(h, vector<bool>(w));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) is_white[i][j] = s[j] == '1';
  }

  int res = 1 << 30;
  for (int bit = 0; bit < (1 << (h - 1)); ++bit) {
    int c = 0, cur = 0;
    vector<int> group(h, 0);    
    for (int i = 0; i < h - 1; ++i) {
      if (bit & (1 << i)) { ++c; ++cur; }
      group[i + 1] = c;
    }
    ++c;
    vector<int> sum(c, 0), add(c, 0);
    bool possible = true;
    for (int j = 0; j < w; ++j) {
      bool over = false;
      for (int i = 0; i < h; ++i) {
        if (is_white[i][j]) {
          ++add[group[i]];
          possible &= add[group[i]] <= k;
          over |= sum[group[i]] + add[group[i]] > k;
        }
      }
      if (over) {
        ++cur;
        for (int i = 0; i < c; ++i) sum[i] = 0;
      }
      for (int i = 0; i < c; ++i) {
        sum[i] += add[i];
        add[i] = 0;
      }    
    }
    if (possible) res = min(res, cur);
  }
  cout << res << endl;
  return 0;
}
