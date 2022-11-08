#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  
  vector<int> nx(n, -1);  
  for (int i = 0; i < n; ++i) { cin >> nx[i]; --nx[i]; }
  
  int logk = 31;
  vector<vector<int> > db(logk, vector<int>(n, -1));
  vector<vector<long long> > dist(logk, vector<long long>(n, 0));
  for (int i = 0; i < n; ++i) db[0][i] = nx[i];
  for (int i = 0; i < logk - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      db[i + 1][j] = db[i][db[i][j]];
    }
  }

  auto func = [&](int x, int y) -> int {
    for (int i = 0; y > 0; ++i) {
      if (y & 1) x = db[i][x];
      y >>= 1;
    }
    return x + 1;
  };

  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << func(--x, y) << endl;
  }  
  
  return 0;
}
