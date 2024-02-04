#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  vector grid(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      grid[i][j] = s[j] == '#' ? 1 : 0;
    }
  }

  vector<int> dr = {-1, 0, 1, 0};
  vector<int> dc = {0, 1, 0, -1};
  int r = 0, c = 0, dir = 0;
  auto Move = [&]() -> void {
    r = (r + dr[dir] + h) % h;
    c = (c + dc[dir] + w) % w;
  };

  while (n--) {
    if (grid[r][c]) {
      dir = (dir + 3) % 4;
    } else {
      dir = (dir + 1) % 4;
    }
    grid[r][c] ^= 1;
    Move();
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << (grid[i][j] ? '#' : '.');
    }
    cout << endl;
  }

  return 0;
}