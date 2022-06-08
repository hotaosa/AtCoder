#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  int q;
  cin >> q;
  while (q--) {
    int x, k;
    cin >> x >> k;    
    set<int> se;
    queue<pair<int, int> > que;
    que.emplace(--x, 0);
    int res = 0;
    while (!que.empty()) {
      int v = que.front().first;
      int d = que.front().second;
      que.pop();
      if (se.insert(v).second) {
        res += v + 1;
        if (d < k) for (int nv : graph[v]) que.emplace(nv, d + 1);
      }      
    }
    cout << res << endl;
  }
  return 0;
}
