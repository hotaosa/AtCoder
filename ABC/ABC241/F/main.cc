#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, n, sx, sy, gx, gy;
  cin >> h >> w >> n >> sx >> sy >> gx >> gy;

  map<int, set<int> > obj_x, obj_y;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;    
    obj_x[x].insert(y);
    obj_y[y].insert(x);
  }

  map<int, map<int, int> > res;
  res[sx][sy] = 1;
  queue<pair<int, int> > que;
  que.push(make_pair(sx, sy));

  while (!que.empty()) {
    int x = que.front().first, y = que.front().second;
    que.pop();

    auto py = obj_x[x].lower_bound(y);
    auto px = obj_y[y].lower_bound(x);
    if (py != obj_x[x].end()) {
      int ny = *py - 1;
      if (res[x][ny] == 0) {
        res[x][ny] = res[x][y] + 1;
        que.push(make_pair(x, ny));
      }
    }
    if (py != obj_x[x].begin()) {
      int ny = *(--py) + 1;
      if (res[x][ny] == 0) {
        res[x][ny] = res[x][y] + 1;
        que.push(make_pair(x, ny));
      }
    }    
    if (px != obj_y[y].end()) {
      int nx = *px - 1;
      if (res[nx][y] == 0) {
        res[nx][y] = res[x][y] + 1;
        que.push(make_pair(nx, y));
      }
    }
    if (px != obj_y[y].begin()) {
      int nx = *(--px) + 1;
      if (res[nx][y] == 0) {
        res[nx][y] = res[x][y] + 1;
        que.push(make_pair(nx, y));
      }
    }
  }
  cout << (res[gx][gy] ? res[gx][gy] - 1: -1) << endl;
  return 0;
}
