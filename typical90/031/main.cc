#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> w(n), b(n);
  for (auto &p : w) cin >> p;
  for (auto &p : b) cin >> p;

  const int SIZE_W = 51;
  const int SIZE_B = 51 + 50 * 51 / 2;
  vector<vector<int> > grundy(SIZE_W, vector<int>(SIZE_B, -1));  

  for (int i = 0; i < SIZE_W; ++i) {
    for (int j = 0; j < SIZE_B; ++j) {
      vector<bool> exist(SIZE_B, false);
      if (i > 0 && j + i < SIZE_B) exist[grundy[i - 1][j + i]] = true;
      for (int k = 1; k <= j / 2; ++k) exist[grundy[i][j - k]] = true;
      int g = 0;
      while (exist[g]) ++g;
      grundy[i][j] = g;
    }
  }  

  int xsum = 0;
  for (int i = 0; i < n; ++i) xsum ^= grundy[w[i]][b[i]];
  cout << (xsum ? "First" : "Second") << endl;
  return 0;
}
