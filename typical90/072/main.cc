#include <iostream>
#include <vector>
#include <string>

std::vector<int> dr = {1, 0, -1, 0};
std::vector<int> dc = {0, 1, 0, -1};

void dfs(std::vector<std::vector<bool> > &visited, std::vector<std::vector<bool> > &is_mountain,
         const int &gr, const int &gc, int r, int c, int len, int &res) {
  visited[r][c] = true;
  for (int i = 0; i < 4; ++i) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr == gr && nc == gc && len >= 3) res = std::max(res, len + 1);
    if (nr < 0 || nc < 0 || nr > (int)visited.size() - 1 || nc > (int)visited[0].size() - 1) continue;
    if (is_mountain[nr][nc] || visited[nr][nc]) continue;
    dfs(visited, is_mountain, gr, gc, nr, nc, len + 1, res);
  }
  visited[r][c] = false;
}

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<bool> > is_mountain(h, std::vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) if (s[j] == '#') is_mountain[i][j] = true;
  }

  int res = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (is_mountain[i][j]) continue;
      std::vector<std::vector<bool> > visited(h, std::vector<bool>(w, false));
      dfs(visited, is_mountain, i, j, i, j, 0, res);
    }
  }

  std::cout << res << std::endl;
  return 0;
}
