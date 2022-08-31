#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int> > a(h, vector<int>(w));
  vector<vector<int> > b(h, vector<int>(w));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) cin >> a[i][j];
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) cin >> b[i][j];

  long long res = 0;
  for (int i = 0; i < h - 1; ++i) {
    for (int j = 0; j < w - 1; ++j) {
      int diff = b[i][j] - a[i][j];
      res += abs(diff);
      for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) {
          a[i + k][j + l] += diff;
        }
      }
    }
  }

  bool ok = true;
  for (int i = 0; i < h; ++i) ok &= a[i][w - 1] == b[i][w- 1];
  for (int i = 0; i < w; ++i) ok &= a[h - 1][i] == b[h - 1][i];

  if (ok) {
    cout << "Yes" << endl;
    cout << res << endl;
  } else {
    cout << "No" << endl;
  }  
  return 0;
}
