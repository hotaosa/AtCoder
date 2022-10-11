#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  auto in_grid = [&](int r, int c) -> bool {
    return r >= 0 && r < n && c >= 0 && c < n;
  };

  vector<int> dr, dc;
  for (int i = 0; i < n && i * i <= m; ++i) {
    int j = (int)sqrt(m - i * i);
    if (i * i + j * j == m) {
      dr.push_back(i); dc.push_back(j);
      dr.push_back(-i); dc.push_back(j);
      dr.push_back(i); dc.push_back(-j);
      dr.push_back(-i); dc.push_back(-j);
    }
  }
  int siz = dr.size();

  vector<vector<int> > dist(n, vector<int>(n, -1));
  dist[0][0] = 0;

  queue<pair<int, int> > que;
  que.emplace(0, 0);

  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    for (int i = 0; i < siz; ++i) {
      int nr = r + dr[i], nc = c + dc[i];
      if (in_grid(nr, nc) && dist[nr][nc] == -1) {
        dist[nr][nc] = dist[r][c] + 1;
        que.emplace(nr, nc);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }  
  return 0;
}
