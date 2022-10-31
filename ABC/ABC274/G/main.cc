#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<bool> > is_wall(h, vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) is_wall[i][j] = s[j] == '#';
  }

  int cnt_r = 0, cnt_c = 0;
  vector<vector<int> > id_r(h, vector<int>(w, -1)), id_c(h, vector<int>(w, -1));

  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (is_wall[r][c]) continue;
      if (!is_wall[r][c]) {
        if (c > 0 && !is_wall[r][c - 1]) id_r[r][c] = cnt_r;
        else id_r[r][c] = ++cnt_r;
      }      
    }
  }  

  for (int c = 0; c < w; ++c) {
    for (int r = 0; r < h; ++r) {
      if (is_wall[r][c]) continue;
      if (!is_wall[r][c]) {
        if (r > 0 && !is_wall[r - 1][c]) id_c[r][c] = cnt_c;
        else id_c[r][c] = ++cnt_c;
      }
    }
  }

  int cnt = ++cnt_r + ++cnt_c;
  
  atcoder::mf_graph<int> graph(cnt + 2);
  for (int i = 0; i < cnt_r; ++i) graph.add_edge(cnt, i, 1);
  for (int i = 0; i < cnt_c; ++i) graph.add_edge(cnt_r + i, cnt + 1, 1);  

  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (is_wall[r][c]) continue;
      graph.add_edge(id_r[r][c], cnt_r + id_c[r][c], INF);
    }
  }

  cout << graph.flow(cnt, cnt + 1) << endl;
  return 0;
}
