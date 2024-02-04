#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int s1 = -1, s2 = -1;
  vector<bool> is_wall(n * n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      is_wall[i * n + j] = s[j] == '#';
      if (s[j] == 'P') {
        (s1 == -1 ? s1 : s2) = i * n + j;
      }
    }
  }

  auto Move = [&](int v, int dir) -> int {
    switch (dir) {
      case 0:
        if (v % n < n - 1 && !is_wall[v + 1]) ++v;
        break;
      case 1:
        if (v % n > 0 && !is_wall[v - 1]) --v;
        break;
      case 2:
        if (v / n < n - 1 && !is_wall[v + n]) v += n;
        break;
      default:
        if (v / n > 0 && !is_wall[v - n]) v -= n;
        break;
    }
    return v;
  };

  int res = -1;
  vector dist(n * n, vector<int>(n * n, -1));
  dist[s1][s2] = 0;
  queue<pair<int, int> > que;
  que.emplace(s1, s2);

  while (!que.empty()) {
    auto [v1, v2] = que.front();
    que.pop();
    if (v1 == v2) {
      res = dist[v1][v2];
      break;
    }
    for (int i = 0; i < 4; ++i) {
      int nv1 = Move(v1, i);
      int nv2 = Move(v2, i);
      if (dist[nv1][nv2] == -1) {
        dist[nv1][nv2] = dist[v1][v2] + 1;
        que.emplace(nv1, nv2);
      }
    }
  }

  cout << res << endl;
  return 0;
}