#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> par(n, -1), cnt(n, 1);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    par[i] = --p;
    ++cnt[p];
  }

  while (q--) {
    set<int> se;
    int m;
    cin >> m;    
    for (int i = 0; i < m; ++i) {
      int v;
      cin >> v;
      se.insert(--v);
    }
    int res = 0;
    for (auto s : se) {
      res += cnt[s];
      if (se.count(par[s])) res -= 2;
    }
    cout << res << endl;
  }  
  return 0;
}
