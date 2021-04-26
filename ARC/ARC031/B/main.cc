#include <iostream>
#include <string>
#include <vector>

void dfs(const std::vector<std::vector<bool>> &land,
         std::vector<std::vector<bool>> &visited, int r, int c, int &cnt) {
  visited[r][c] = true;
  ++cnt;
  std::vector<int> dr = {1, 0, -1, 0};
  std::vector<int> dc = {0, 1, 0, -1};
  for (int i = 0; i < 4; ++i) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr < 0 || nr > 9 || nc < 0 || nc > 9 || !land[nr][nc] || visited[nr][nc]) continue;
    dfs(land, visited, nr, nc, cnt);
  }
}

int main() {
  std::vector<std::vector<bool>> land(10, std::vector<bool>(10, false));
  int tot = 0;
  for (int i = 0; i < 10; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < 10; ++j) if (s[j] == 'o') { land[i][j] = true; ++tot; }
  }
  
  std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
  int cnt = -1;
  dfs(land, visited, 8, 1, cnt);

  bool possible = false;
  for (int i = 0; i < 10 && !possible; ++i) {
    for (int j = 0; j < 10 && !possible; ++j) {
      if (land[i][j]) continue;
      std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
      int cnt = -1;
      dfs(land, visited, i, j, cnt);
      if (cnt == tot) possible = true;
    }
  }
  
  std::cout << (possible ? "YES" : "NO") << std::endl;
  return 0;  
}
