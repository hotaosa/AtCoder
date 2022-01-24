#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

void calc(const vector<vector<int> > &a, int &res, int used, int cur, int v) {
  const int n = a.size();
  used |= (1 << v);
  for (int pa = v + 1; pa < n; ++pa) {
    if (used & (1 << pa)) continue;
    int nx = -1;
    for (int i = v + 1; i < n; ++i) if (i != pa && !(used & (1 << i))) { nx = i; break; }
    if (nx == -1) {
      res = max(res, cur ^ a[v][pa]);
      return;
    } else {
      calc(a, res, used | (1 << pa), cur ^ a[v][pa], nx);
    }
  }
}

int main() {
  int n;
  cin >> n;
  n *= 2;

  vector<vector<int> > a(n, vector<int>(n, 0));
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) cin >> a[i][j];
  }

  int res = 0;
  calc(a, res, 0, 0, 0);
  cout << res << endl;
  return 0;
}
