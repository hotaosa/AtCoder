#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  vector<int> col(n, -1);
  vector<vector<int> > vec(2);
  col[0] = 0;
  vec[0].push_back(0);
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (col[nv] != -1) continue;
      col[nv] = col[v] ^ 1;
      vec[col[nv]].push_back(nv);
      que.push(nv);
    }
  }

  if ((int)vec[0].size() >= n / 2) {
    for (int i = 0; i < n / 2; ++i) cout << vec[0][i] + 1 << " ";
    cout << endl;
  } else {
    for (int i = 0; i < n / 2; ++i) cout << vec[1][i] + 1 << " ";
    cout << endl;
  }
  return 0;
}
