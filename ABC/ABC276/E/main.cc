#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  auto to_1d = [&](int r, int c) -> int {
    return r * w + c;
  };
  
  vector<vector<bool> > is_wall(h, vector<bool>(w, false));
  int sr, sc;
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      is_wall[i][j] = s[j] != '.';
      if (s[j] == 'S') { sr = i; sc = j; }
    }
  }

  atcoder::dsu uf(h * w);
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (is_wall[r][c]) continue;
      if (r < h - 1 && !is_wall[r + 1][c]) uf.merge(to_1d(r, c), to_1d(r + 1, c));
      if (c < w - 1 && !is_wall[r][c + 1]) uf.merge(to_1d(r, c), to_1d(r, c + 1));
    }
  }

  vector<int> adjacent;
  if (sr > 0 && !is_wall[sr - 1][sc]) adjacent.push_back(to_1d(sr - 1, sc));
  if (sc > 0 && !is_wall[sr][sc - 1]) adjacent.push_back(to_1d(sr, sc - 1));
  if (sr < h - 1 && !is_wall[sr + 1][sc]) adjacent.push_back(to_1d(sr + 1, sc));
  if (sc < w - 1 && !is_wall[sr][sc + 1]) adjacent.push_back(to_1d(sr, sc + 1));

  bool exist = false;
  for (auto i : adjacent) {
    for (auto j : adjacent) {
      if (i == j) continue;
      exist |= uf.same(i, j);
    }
  }

  cout << (exist ? "Yes" : "No" ) << endl;  
  return 0;
}
