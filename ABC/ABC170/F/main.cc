#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int h, w, k, x1, y1, x2, y2;
  cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
  --x1; --y1; --x2; --y2;

  vector<vector<bool> > is_wall(h, vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) if (s[j] == '@') is_wall[i][j] = true;
  }

  vector<vector<vector<pair<int, int> > > > dist(h, vector<vector<pair<int, int> > >(w, vector<pair<int, int> >(4, {INF, 0})));
  for (int i = 0; i < 4; ++i) dist[x1][y1][i] = {0, 0};

  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  
  priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int> >, greater<> > pque;
  pque.emplace(0, 0, 0, x1, y1);

  while (!pque.empty()) {
    int d = get<0>(pque.top());
    int rem = get<1>(pque.top());
    int dir = get<2>(pque.top());
    int x = get<3>(pque.top());
    int y = get<4>(pque.top());
    pque.pop();
    if (make_pair(d, rem) > dist[x][y][dir]) continue;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx == -1 || nx == h || ny == -1 || ny == w || is_wall[nx][ny]) continue;
      if (i == dir && rem != 0) {
        if (chmin(dist[nx][ny][i], {d, rem + 1})) pque.emplace(d, rem + 1, i, nx, ny);        
      } else {
        if (chmin(dist[nx][ny][i], {d + 1, 1 - k})) pque.emplace(d + 1, 1 - k, i, nx, ny);
      }
    }
  }

  int res = INF;
  for (int i = 0; i < 4; ++i) chmin(res, dist[x2][y2][i].first);
  cout << (res < INF ? res : -1) << endl;
  return 0;
}
