#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

bool chmin(int &a, int b) {
  if (b < a) { a = b; return true; }
  return false;
}

int main() {
  const int INF = 1 << 30;
  int h, w;
  int rs, cs, rt, ct;
  std::cin >> h >> w >> rs >> cs >> rt >> ct;
  --rs;
  --cs;
  --rt;
  --ct;
  
  std::vector<std::vector<bool> > is_wall(h, std::vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) if (s[j] == '#') is_wall[i][j] = true;
  }

  std::vector<std::vector<std::vector<int> > > dist(h, std::vector<std::vector<int> > (w, std::vector<int>(4, INF)));
  std::vector<int> dr = {1, 0, -1, 0};
  std::vector<int> dc = {0, 1, 0, -1};
  std::queue<std::tuple<int, int, int> > que;
  for (int i = 0; i < 4; ++i) {
    int nr = rs + dr[i];
    int nc = cs + dc[i];
    if (nr < 0 || nr >= h || nc < 0 || nc >= w || is_wall[nr][nc]) continue;
    dist[nr][nc][i] = 0;
    que.push(std::make_tuple(nr, nc, i));
  }

  while (!que.empty()) {
    int r = std::get<0>(que.front());
    int c = std::get<1>(que.front());
    int dir = std::get<2>(que.front());
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr < 0 || nr >= h || nc < 0 || nc >= w || is_wall[nr][nc]) continue;
      if (chmin(dist[nr][nc][i], dist[r][c][dir] + (i == dir ? 0 : 1))) {
        que.push(std::make_tuple(nr, nc, i));
      }
    }
  }

  int res = INF;
  for (int i = 0; i < 4; ++i) res = std::min(res, dist[rt][ct][i]);
  std::cout << res << std::endl;
  return 0;
}
