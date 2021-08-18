#include <iostream>
#include <string>
#include <vector>
#include <deque>

bool chmin(int &a, int b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  const int INF = 1 << 30;
  int h, w;
  std::cin >> h >> w;

  std::vector<std::vector<bool> > is_wall(h, std::vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) if (s[j] == '#') is_wall[i][j] = true;
  }

  std::vector<int> dr_0 = {1, 0, -1, 0};
  std::vector<int> dc_0 = {0, 1, 0, -1};

  std::vector<int> dr_1 = {-2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2};
  std::vector<int> dc_1 = {-1, 0, 1, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -1, 0, 1};

  std::vector<std::vector<int> > dist(h, std::vector<int>(w, INF));
  dist[0][0] = 0;
  std::deque<std::pair<int, int> > dq;
  dq.push_front(std::make_pair(0, 0));
  while (!dq.empty()) {
    int r = dq.front().first;
    int c = dq.front().second;
    dq.pop_front();
    for (int i = 0; i < 4; ++i) {
      int nx_r = r + dr_0[i];
      int nx_c = c + dc_0[i];
      if (nx_r < 0 || nx_r >= h || nx_c < 0 || nx_c >= w || is_wall[nx_r][nx_c]) continue;
      if (chmin(dist[nx_r][nx_c], dist[r][c])) dq.push_front(std::make_pair(nx_r, nx_c));
    }
    for (int i = 0; i < 20; ++i) {
      int nx_r = r + dr_1[i];
      int nx_c = c + dc_1[i];
      if (nx_r < 0 || nx_r >= h || nx_c < 0 || nx_c >= w) continue;
      if (chmin(dist[nx_r][nx_c], dist[r][c] + 1)) dq.push_back(std::make_pair(nx_r, nx_c));
    }
  }

  std::cout << dist[h - 1][w - 1] << std::endl;
  return 0;
}
