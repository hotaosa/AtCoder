#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  vector<vector<int> > cnt(h + 1, vector<int>(w + 1, 0));
  for (int i = 0; i < n; ++i) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    --r1; --c1; --r2; --c2;
    ++cnt[r1][c1];
    --cnt[r1][c2 + 1];
    --cnt[r2 + 1][c1];
    ++cnt[r2 + 1][c2 + 1];
  }

  for (int i = 0; i < h; ++i) for (int j = 1; j < w; ++j) cnt[i][j] += cnt[i][j - 1];
  for (int j = 0; j < w; ++j) for (int i = 1; i < h; ++i) cnt[i][j] += cnt[i - 1][j];

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << cnt[i][j] << " " ;      
    }
    cout << endl;
  }
  
  return 0;
}
