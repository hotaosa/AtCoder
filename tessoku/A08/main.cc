#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int> > x(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> x[i][j];
      if (j > 0) x[i][j] += x[i][j - 1];
    }
  }
  for (int j = 0; j < w; ++j) {
    for (int i = 1; i < h; ++i) {
      x[i][j] += x[i - 1][j];
    }
  }

  auto func = [&](int r, int c) -> int {
    if (--r < 0 || --c < 0) return 0;
    else return x[r][c];
  };
  
  int q;
  cin >> q;
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << func(r2, c2) - func(r2, c1 - 1) - func(r1 - 1, c2) + func(r1 - 1, c1 - 1) << endl;
  }

  return 0;
}
