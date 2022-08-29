#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  vector<string> grid(h);
  for (auto &p : grid) cin >> p;

  int dr[] = {1, 0, -1, 0};
  int dc[] = {0, 1, 0, -1};  

  int res = 1;
  for (int i = 0; i < 4; ++i) {
    int r = x - 1 + dr[i], c = y - 1 + dc[i];
    while (r >= 0 && r < h && c >= 0 && c < w && grid[r][c] == '.') {
      ++res;
      r += dr[i];
      c += dc[i];
    }
  }

  cout << res << endl;  
  return 0;
}
