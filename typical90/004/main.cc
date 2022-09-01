#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int> > a(h, vector<int>(w));
  vector<int> sum_r(h, 0), sum_c(w, 0);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
      sum_r[i] += a[i][j];
      sum_c[j] += a[i][j];
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << sum_r[i] + sum_c[j] - a[i][j] << " ";
    }
    cout << endl;
  }  
  return 0;
}
