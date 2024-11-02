#include <iostream>
#include <string>
#include <vector>

int main() {
  int h, w, k;
  std::cin >> h >> w >> k;

  std::vector grid(h, std::vector<int>(w));
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) {
      grid[i][j] = s[j] == '#' ? -1 : 0;
    }
  }

  std::vector<int> dr{1, 0, -1, 0};
  std::vector<int> dc{0, 1, 0, -1};

  auto Dfs = [&](auto self, int r, int c, int k) -> int {
    if (k == 0) return 1;
    grid[r][c] = 1;
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] == 0) {
        ret += self(self, nr, nc, k - 1);
      }
    }
    grid[r][c] = 0;
    return ret;
  };

  int res = 0;
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (grid[r][c] == 0) {
        res += Dfs(Dfs, r, c, k);
      }
    }
  }

  std::cout << res << "\n";
  return 0;
}