#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  int n = h * w;
  vector<bool> is_wall(n, false);
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) is_wall[i * w + j] = s[j] == '#';
  }

  auto make_next = [&](int v) -> vector<int> {
    vector<int> nx;
    if (v / w > 0 && !is_wall[v - w]) nx.push_back(v - w);
    if (v / w < h - 1 && !is_wall[v + w]) nx.push_back(v + w);
    if (v % w > 0 && !is_wall[v - 1]) nx.push_back(v - 1);
    if (v % w < w - 1 && !is_wall[v + 1]) nx.push_back(v + 1);
    return nx;
  };

  int res = -1;
  set<int> se;

  auto dfs = [&](auto dfs, int v, int p, int g) -> void {    
    se.insert(v);
    auto nx = make_next(v);
    for (int nv : nx) {
      if (nv != p && nv == g) res = max(res, (int)se.size());
      if (!se.count(nv)) dfs(dfs, nv, v, g);
    }
    se.erase(v);
  };

  for (int v = 0; v < n; ++v) if (!is_wall[v]) dfs(dfs, v, -1, v);
  cout << res << endl;
  return 0;
}
