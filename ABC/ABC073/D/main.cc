#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = 1LL << 60;

bool chmin(long long &a, long long b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m, r;
  std::cin >> n >> m >> r;

  std::vector<int> vr(r);
  for (int i = 0; i < r; ++i) { std::cin >> vr[i]; --vr[i]; }
  std::sort(vr.begin(), vr.end());

  std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, INF));
  for (int i = 0; i < n; ++i) dist[i][i] = 0LL;
  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    std::cin >> a >> b >> c;
    --a; --b;
    dist[a][b] = dist[b][a] = c;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  long long res = INF;
  do {
    long long d = 0;
    for (int i = 0; i < r - 1; ++i) d += dist[vr[i]][vr[i + 1]];
    chmin(res, d);    
  } while (std::next_permutation(vr.begin(), vr.end()));

  std::cout << res << std::endl;
  return 0;  
}
