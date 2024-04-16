#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  int sr, sc, tr, tc;
  vector grid(h, vector<int>(w, -1));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      if (s[j] == 'S') {
        sr = i;
        sc = j;
      } else if (s[j] == 'T') {
        tr = i;
        tc = j;
      } else if (s[j] == '#') {
        grid[i][j] = -2;
      }
    }
  }

  int n;
  cin >> n;
  n += 2;
  vector<int> posr(n), posc(n), energy(n, 0);
  posr[0] = sr;
  posc[0] = sc;
  grid[sr][sc] = 0;
  posr[n - 1] = tr;
  posc[n - 1] = tc;
  grid[tr][tc] = n - 1;
  for (int i = 1; i < n - 1; ++i) {
    cin >> posr[i] >> posc[i] >> energy[i];
    grid[--posr[i]][--posc[i]] = i;
    if (posr[i] == sr && posc[i] == sc) {
      energy[0] = energy[i];
    }
  }

  vector<int> dr = {1, 0, -1, 0};
  vector<int> dc = {0, 1, 0, -1};

  vector<bool> reachable(n, false);
  reachable[0] = true;
  queue<int> que1;
  que1.emplace(0);
  while (!que1.empty()) {
    int v = que1.front();
    que1.pop();
    vector dist(h, vector<int>(w, -1));
    dist[posr[v]][posc[v]] = 0;
    queue<pair<int, int>> que2;
    que2.emplace(posr[v], posc[v]);

    while (!que2.empty()) {
      auto [r, c] = que2.front();
      que2.pop();
      if (dist[r][c] > energy[v]) break;
      int id = grid[r][c];
      if (id > 0 && !reachable[id]) {
        reachable[id] = true;
        que1.emplace(id);
      }
      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= h || nc < 0 || nc >= w || grid[nr][nc] == -2 ||
            dist[nr][nc] != -1)
          continue;
        dist[nr][nc] = dist[r][c] + 1;
        que2.emplace(nr, nc);
      }
    }
  }

  cout << (reachable.back() ? "Yes" : "No") << endl;
  return 0;
}