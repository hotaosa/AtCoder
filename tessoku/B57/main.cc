#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int func(int n) {
  int sum = 0, m = n;
  while (m) {
    sum += m % 10;
    m /= 10;
  }
  return n - sum;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> nx(n + 1, 0);
  for (int i = 10; i <= n; ++i) nx[i] = func(i);
  
  int logk = 1;
  while ((1LL << logk) <= k) ++logk;
  vector<vector<int> > db(logk, vector<int>(n + 1, -1));
  for (int i = 0; i <= n; ++i) db[0][i] = nx[i];
  for (int i = 0; i < logk - 1; ++i) {
    for (int j = 0; j <= n; ++j) {
      db[i + 1][j] = db[i][db[i][j]];
    }
  }

  auto solve = [&](int x, int m) -> int {
    int cur = x;
    for (int i = 0; m > 0; ++i) {
      if (m & 1) cur = db[i][cur];
      m >>= 1;
    }
    return cur;
  };
  
  for (int i = 1; i <= n; ++i) cout << solve(i, k) << endl;
  return 0;
}
