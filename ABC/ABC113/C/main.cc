#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<pair<int, int> > res(m);
  vector<vector<pair<int, int> > > vvp(n);
  for (int i = 0; i < m; ++i) {
    int p, y;
    cin >> p >> y;
    vvp[--p].emplace_back(y, i);
  }
  for (auto &v : vvp) sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)vvp[i].size(); ++j) {
      res[vvp[i][j].second] = {i + 1, j + 1};
    }
  }

  for (int i = 0; i < m; ++i) printf("%06d%06d\n", res[i].first, res[i].second);
  return 0;
}
