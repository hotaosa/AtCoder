#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n - 1));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n - 1; ++j) { cin >> a[i][j]; --a[i][j]; }

  auto to_1d = [&](int i, int j) -> int {
    return i * n + j;
  };

  vector<int> deg(n * n, 0);
  vector<vector<int> > graph(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 2; ++j) {
      int u = to_1d(min(i, a[i][j]), max(i, a[i][j]));
      int v = to_1d(min(i, a[i][j + 1]), max(i, a[i][j + 1]));
      graph[u].push_back(v);
      ++deg[v];
    }
  }

  queue<int> que1, que2;
  for (int i = 0; i < n * n; ++i) if (deg[i] == 0) que1.push(i);

  int cnt = 0, res = 0;
  while (!que1.empty()) {
    ++res;
    while (!que1.empty()) {
      int v = que1.front();
      que1.pop();
      ++cnt;
      for (int nv : graph[v]) if (--deg[nv] == 0) que2.push(nv);
    }
    while (!que2.empty()) {
      que1.push(que2.front());
      que2.pop();
    }
  }

  if (cnt < n * n) cout << "-1" << endl;
  else cout << res << endl;  
  return 0;
}
