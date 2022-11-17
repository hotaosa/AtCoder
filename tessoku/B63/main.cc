#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, sr, sc, gr, gc;
  cin >> h >> w >> sr >> sc >> gr >> gc;

  vector<vector<bool> > is_wall(h, vector<bool>(w));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) is_wall[i][j] = s[j] == '#';
  }

  vector<vector<int> > dist(h, vector<int>(w, -1));
  dist[--sr][--sc] = 0;

  queue<pair<int, int> > que;
  que.emplace(sr, sc);

  int dr[] = {1, 0, -1, 0};
  int dc[] = {0, 1, 0, -1};

  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr < 0 || nr >= h || nc < 0 || nc >= w || is_wall[nr][nc] || dist[nr][nc] != -1) continue;
      dist[nr][nc] = dist[r][c] + 1;
      que.emplace(nr, nc);
    }
  }

  cout << dist[--gr][--gc] << endl;  
  return 0;
}
