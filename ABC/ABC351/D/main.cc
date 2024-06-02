#include <iostream>
#include <set>
#include <vector>
//
#include <atcoder/dsu>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector is_wall(h, vector<bool>(w, false));
  vector moveable(h, vector<bool>(w, true));

  vector<int> dr = {1, 0, -1, 0};
  vector<int> dc = {0, 1, 0, -1};

  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      if (s[j] == '#') {
        is_wall[i][j] = true;
        moveable[i][j] = false;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dr[k];
          int nj = j + dc[k];
          if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
            moveable[ni][nj] = false;
          }
        }
      }
    }
  }

  const int n = h * w;
  atcoder::dsu uf(n);
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (!moveable[r][c]) continue;
      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && moveable[nr][nc]) {
          uf.merge(r * w + c, nr * w + nc);
        }
      }
    }
  }

  vector<set<int>> add(n);
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (is_wall[r][c] || moveable[r][c]) continue;
      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && moveable[nr][nc]) {
          add[uf.leader(nr * w + nc)].insert(r * w + c);
        }
      }
    }
  }

  int res = 0;
  for (auto &g : uf.groups()) {
    res = max(res, int(size(g) + size(add[uf.leader(g[0])])));
  }

  cout << res << endl;
  return 0;
}