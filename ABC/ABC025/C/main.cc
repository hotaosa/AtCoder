#include <bits/stdc++.h>

std::pair<int, int> dfs(std::vector<std::vector<int>> &board, std::vector<std::vector<int>> &b,
                        std::vector<std::vector<int>> &c, bool turn, int cnt) {
  if (cnt == 9) {
    int p1 = 0, p2 = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        (board[i][j] == board[i + 1][j] ? p1 : p2) += b[i][j];
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 2; ++j) {
        (board[i][j] == board[i][j + 1] ? p1 : p2) += c[i][j];
      }
    }
    return {p1, p2};
  }

  std::pair<int, int> ret = {-1, -1};
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (board[i][j] != -1) continue;
      board[i][j] = (turn ? 1 : 0);
      std::pair<int, int> r = dfs(board, b, c, !turn, cnt + 1);
      if (ret.first < 0) ret = r;
      else {
        bool ud = (turn ? ret.first < r.first : ret.second < r.second);
        if (ud) ret = r;
        ud = (turn ? (ret.first == r.first && ret.second > r.second) :
              (ret.second == r.second && ret.first > r.first));
        if (ud) ret = r;
      }
      board[i][j] = -1;
    }
  }
  return ret;
}

int main() {
  std::vector<std::vector<int>> board(3, std::vector<int>(3, -1));
  std::vector<std::vector<int>> b(2, std::vector<int>(3));
  std::vector<std::vector<int>> c(3, std::vector<int>(2));
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 3; ++j) std::cin >> b[i][j];
  for (int i = 0; i < 3; ++i) for (int j = 0; j < 2; ++j) std::cin >> c[i][j];
  std::pair<int, int> res = dfs(board, b, c, true, 0);
  std::cout << res.first << std::endl << res.second << std::endl;
  return 0;  
}
