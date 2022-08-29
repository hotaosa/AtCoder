#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n - 1), b(n - 1);
  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }

  vector<int> depth(n, -1);
  depth[0] = 0;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (depth[nv] == -1) {
        depth[nv] = depth[v] + 1;
        que.push(nv);
      }
    }
  }
  
  vector<long long> res(n, 0);
  int q;
  cin >> q;
  while (q--) {
    int t, e;
    long long x;
    cin >> t >> e >> x;
    --e;
    int u = (t == 1 ? b[e] : a[e]);
    int v = (t == 1 ? a[e] : b[e]);    
    if (depth[u] < depth[v]) {
      res[v] += x;
    } else {
      res[0] += x;
      res[u] -= x;
    }
  }  
  
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (depth[nv] > depth[v]) {        
        res[nv] += res[v];
        que.push(nv);
      }
    }
  }

  for (auto r : res) cout << r << endl;  
  return 0;
}
