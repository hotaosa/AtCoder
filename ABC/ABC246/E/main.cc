#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, ax, ay, bx, by;
  cin >> n >> ax >> ay >> bx >> by;
  --ax; --ay; --bx; --by;

  int dx[] = {1, 1, -1, -1};
  int dy[] = {1, -1, 1, -1};

  vector<vector<bool> > is_empty(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) is_empty[i][j] = (s[j] == '.');
  }

  vector<vector<vector<int> > > dist(n, vector<vector<int> > (n, vector<int>(4, 1 << 30)));  
  for (int i = 0; i < 4; ++i) dist[ax][ay][i] = 0;
  deque<tuple<int, int, int> > dq;
  dq.push_back({ax, ay, -1});
  
  while (!dq.empty()) {
    int x = get<0>(dq.front());
    int y = get<1>(dq.front());
    int from = get<2>(dq.front());
    dq.pop_front();
    if (x == bx && y == by) { cout << dist[x][y][from] << endl; return 0; }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < n && is_empty[nx][ny]) {
        if (i == from && chmin(dist[nx][ny][i], dist[x][y][from])) dq.push_front({nx, ny, i});
        if (i != from && chmin(dist[nx][ny][i], dist[x][y][max(0, from)] + 1)) dq.push_back({nx, ny, i});
      }
    }
  }
  cout << "-1" << endl;
  return 0;
}
