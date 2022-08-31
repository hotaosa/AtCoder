#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> res;
  queue<int> que;
  vector<vector<int> > graph(n);

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (a == i || b == i) que.push(i);
    else {
      graph[a].push_back(i);
      graph[b].push_back(i);
    }
  }

  vector<bool> used(n, false);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (used[v]) continue;
    used[v] = true;    
    res.push_back(v + 1);
    for (int nv : graph[v]) if (!used[nv]) que.push(nv);
  }

  if ((int)res.size() < n) cout << "-1" << endl;
  else for (int i = n - 1; i >= 0; --i) cout << res[i] << endl;  
  return 0;
}
