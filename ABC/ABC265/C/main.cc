#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  for (int i = 0; i < h; ++i) cin >> grid[i];

  int r = 0, c = 0;
  while (true) {
    if (grid[r][c] == 'U') {
      if (r == 0) break;
      grid[r][c] = 'X';
      --r;
    } else if (grid[r][c] == 'D') {
      if (r == h - 1) break;
      grid[r][c] = 'X';
      ++r;
    } else if (grid[r][c] == 'L') {
      if (c == 0) break;
      grid[r][c] = 'X';
      --c;
    } else if (grid[r][c] == 'R') {
      if (c == w - 1) break;
      grid[r][c] = 'X';
      ++c;
    } else {
      r = -1;
      c = -1;
      break;
    }
  }
  if (r != -1 && c != -1)  cout << r + 1 << " " << c + 1 << endl;
  else cout << "-1" << endl;
  return 0;
}
