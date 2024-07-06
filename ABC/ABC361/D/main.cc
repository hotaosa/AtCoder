#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int BitSwap(int x, int p1, int p2) {
  int b1 = x >> p1 & 1;
  int b2 = x >> p2 & 1;
  if (b1 == b2) return x;
  int mask = (1 << p1) | (1 << p2);
  return x ^ mask;
}

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  n += 2;

  int x = 0, y = 0;
  for (auto c : s) x = (x << 1) | (c == 'B' ? 1 : 0);
  for (auto c : t) y = (y << 1) | (c == 'B' ? 1 : 0);
  x <<= 2;
  y <<= 2;

  int siz = 1 << n;
  vector dist(siz, vector<int>(n, -1));
  dist[x][0] = 0;

  queue<pair<int, int>> que;
  que.emplace(x, 0);
  while (!que.empty()) {
    auto [b, p] = que.front();
    que.pop();
    for (int np = 0; np < n - 1; ++np) {
      if (np == p || np == p - 1 || np == p + 1) continue;
      int nb = BitSwap(b, p, np);
      nb = BitSwap(nb, p + 1, np + 1);
      if (dist[nb][np] == -1) {
        dist[nb][np] = dist[b][p] + 1;
        que.emplace(nb, np);
      }
    }
  }

  cout << dist[y][0] << endl;
  return 0;
}