#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<vector<int > > p(h, vector<int>(w));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) cin >> p[i][j];

  int res = 0;
  for (int bit = 1; bit < (1 << h); ++bit) {
    vector<int> row_list;
    for (int i = 0; i < h; ++i) if (bit & (1 << i)) row_list.push_back(i);
    vector<int> cnt(h * w + 1, 0);
    for (int c = 0; c < w; ++c) {
      bool all_same = true;
      for (int i = 1; i < (int)row_list.size(); ++i) {
        all_same &= (p[row_list[i]][c] == p[row_list[i - 1]][c]);
      }
      if (all_same) cnt[p[row_list[0]][c]] += row_list.size();
    }
    for (int i = 0; i <= h * w; ++i) res = max(res, cnt[i]);
  }

  cout << res << endl;  
  return 0;
}
