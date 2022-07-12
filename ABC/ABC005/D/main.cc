#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > d(n, vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> d[i][j];

  vector<vector<int> > sum(n, vector<int>(n));  
  for (int i = 0; i < n; ++i) {
    sum[i][0] = d[i][0];
    for (int j = 1; j < n; ++j) {
      sum[i][j] = sum[i][j - 1] + d[i][j];
    }
  }
  for (int j = 0; j < n; ++j) {
    for (int i = 1; i < n; ++i) {
      sum[i][j] += sum[i - 1][j];
    }
  }

  vector<int> mx(n * n + 1, 0);
  for (int ra = 0; ra < n; ++ra) {
    for (int ca = 0; ca < n; ++ca) {
      for (int rb = ra; rb < n; ++rb) {
        for (int cb = ca; cb < n; ++cb) {
          int cnt = (rb - ra + 1) * (cb - ca + 1);
          int cur = sum[rb][cb];
          if (ra > 0) cur -= sum[ra - 1][cb];
          if (ca > 0) cur -= sum[rb][ca - 1];
          if (ra > 0 && ca > 0) cur += sum[ra - 1][ca - 1];
          mx[cnt] = max(mx[cnt], cur);
        }
      }
    }
  }
  for (int i = 1; i <= n * n; ++i) mx[i] = max(mx[i], mx[i - 1]);
  
  int q;
  cin >> q;
  while (q--) {
    int p;
    cin >> p;
    cout << mx[p] << endl;
  }
  return 0;
}