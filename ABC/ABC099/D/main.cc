#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<vector<int> > d(c, vector<int>(c));
  for (int i = 0; i < c; ++i) for (int j = 0; j < c; ++j) cin >> d[i][j];

  vector<vector<int> > cnt(3, vector<int>(c, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int col;
      cin >> col;
      ++cnt[(i + j) % 3][--col];
    }
  }

  int res = 1 << 30;
  for (int i = 0; i < c; ++i) {
    int add_i = 0;
    for (int l = 0; l < c; ++l) add_i += d[l][i] * cnt[0][l];
    for (int j = 0; j < c; ++j) {
      if (j == i) continue;
      int add_j = 0;
      for (int l = 0; l < c; ++l) add_j += d[l][j] * cnt[1][l];
      for (int k = 0; k < c; ++k) {
        if (k == j || k == i) continue;
        int add_k = 0;
        for (int l = 0; l < c; ++l) add_k += d[l][k] * cnt[2][l];
        res = min(res, add_i + add_j + add_k);
      }
    }
  }
  cout << res << endl;  
  return 0;
}
