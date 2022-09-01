#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<int> > black_list(n);
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    black_list[--x].push_back(--y);
    black_list[y].push_back(x);
  }

  map<int, set<int> > mp;

  int sum = 0;
  set<int> se;
  auto dfs = [&](auto dfs, int v) -> bool {
    sum += a[v];
    se.insert(v);
    if (mp.count(sum)) return true;
    mp[sum] = se;

    for (int nv = v + 1; nv < n; ++nv) {
      bool ok = true;
      for (auto b : black_list[nv]) ok &= !se.count(b);
      if (ok && dfs(dfs, nv)) return true;
    }

    sum -= a[v];
    se.erase(v);
    return false;
  };

  int v = 0;
  while (!dfs(dfs, v)) ++v;

  cout << se.size() << endl;
  for (int s : se) cout << s + 1 << " ";
  cout << endl;
  cout << mp[sum].size() << endl;
  for (int s : mp[sum]) cout << s + 1 << " ";
  cout << endl;
  return 0;
}
