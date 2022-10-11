#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  set<pair<int, int> > se;
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    vector<int> x(k);
    for (auto &p : x) cin >> p;
    for (int u = 0; u < k - 1; ++u) {
      for (int v = u + 1; v < k; ++v) {
        se.emplace(min(x[u], x[v]), max(x[u], x[v]));
      }
    }
  }
  cout << ((int)se.size() == n * (n - 1) / 2 ? "Yes" : "No" ) << endl;  
  return 0;
}
