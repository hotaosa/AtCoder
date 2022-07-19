#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int s, t, m;
  cin >> s >> t >> m;

  vector<vector<int> > graph(s + t);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  for (int v = s; v < s + t; ++v) {
    map<int, int> mp;
    for (int nv : graph[v]) {
      for (int nnv : graph[nv]) {
        if (nnv == v) continue;
        if (mp.count(nnv)) {
          cout << v + 1 << " " << nv + 1 << " " << nnv + 1 << " " << mp[nnv] + 1 << endl;
          return 0;
        } else {
          mp[nnv] = nv;
        }
      }
    }
  }
  cout << "-1" << endl;
  return 0;
}