#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<bool> > possible(h, vector<bool>(w, true));

  int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  
  int res = 0;
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (possible[r][c]) {
        ++res;
        if (h > 1 && w > 1) {
          for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w) possible[nr][nc] = false;
          }
        }
      }
    }
  }

  cout << res << endl;  
  return 0;
}
