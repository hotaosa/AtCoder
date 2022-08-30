#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int func(int x) {
  int y = x;
  while (x) {
    y += x % 10;
    x /= 10;
  }
  return y % 100000;
}

int main() {
  int n;
  long long k;
  cin >> n >> k;
  
  int logk = 1;
  while ((1LL << logk) <= k) ++logk;
  vector<vector<int> > db(logk, vector<int>(100000, -1));  
  for (int i = 0; i < 100000; ++i) db[0][i] = func(i);
  for (int i = 0; i < logk - 1; ++i) {
    for (int j = 0; j < 100000; ++j) {
      db[i + 1][j] = db[i][db[i][j]];
    }
  }
  
  int res = n;  
  for (int i = 0; k > 0; ++i) {
    if (k & 1) {      
      res = db[i][res];
    }
    k >>= 1;
  }
  cout << res << endl;
  return 0;
}
