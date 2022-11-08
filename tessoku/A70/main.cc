#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int inibit = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    inibit |= (a << i);
  }

  vector<int> bit(m);
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    bit[i] = (1 << --x) | (1 << --y) | (1 << --z);
  }

  int size = 1 << n;
  vector<vector<int> > graph(size);
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < m; ++j) {
      graph[i].push_back(i ^ bit[j]);
    }
  }

  vector<int> dist(size, -1);
  dist[inibit] = 0;
  queue<int> que;
  que.push(inibit);

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

  cout << dist.back() << endl;
  return 0;
}
