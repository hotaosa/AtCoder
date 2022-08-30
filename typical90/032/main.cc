#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];

  vector<vector<bool> > good(n, vector<bool>(n, true));
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    good[x][y] = good[y][x] = false;
  }

  const int INF = 1 << 30;
  int res = INF;
  vector<int> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;
  do {    
    bool possible = true;
    for (int i = 1; i < n; ++i) possible &= good[order[i]][order[i - 1]];
    if (!possible) continue;

    int cur = 0;
    for (int i = 0; i < n; ++i) cur += a[order[i]][i];
    res = min(res, cur);
  } while (next_permutation(order.begin(), order.end()));

  cout << (res < INF ? res : -1) << endl;  
  return 0;
}
