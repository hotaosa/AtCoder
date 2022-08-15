#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > connected(n, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    connected[min(u, v)][max(u, v)] = 1;
  }

  int res = 0;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (connected[i][j] + connected[j][k] + connected[i][k] == 3) ++res;
      }
    }
  }
  cout << res << endl;
  return 0;
}
