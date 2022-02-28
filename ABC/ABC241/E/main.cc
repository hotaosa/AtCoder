#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;

  vector<int> nx(n, -1);
  vector<long long> c(n, -1);
  for (int i = 0; i < n; ++i) cin >> c[i];
  for (int i = 0; i < n; ++i) nx[i] = (i + c[i]) % n;  
  
  int logk = 1;
  while ((1LL << logk) <= k) ++logk;
  vector<vector<int> > db(logk, vector<int>(n, -1));
  vector<vector<long long> > dist(logk, vector<long long>(n, 0));
  for (int i = 0; i < n; ++i) db[0][i] = nx[i];
  for (int i = 0; i < n; ++i) dist[0][i] = c[i];
  for (int i = 0; i < logk - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      db[i + 1][j] = db[i][db[i][j]];
      dist[i + 1][j] = dist[i][j] + dist[i][db[i][j]];
    }
  }
  
  int cur = 0;
  long long sum = 0;
  for (int i = 0; k > 0; ++i) {
    if (k & 1) {
      sum += dist[i][cur];
      cur = db[i][cur];
    }
    k >>= 1;
  }

  cout << sum << endl;
  return 0;
}
