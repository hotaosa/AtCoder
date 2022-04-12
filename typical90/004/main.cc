#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int> > a(h, vector<int>(w));
  vector<int> row_sum(h, 0), column_sum(w, 0);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
      row_sum[i] += a[i][j];
      column_sum[j] += a[i][j];
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << row_sum[i] + column_sum[j] - a[i][j] << " ";
    }
    cout << endl;
  }  
  return 0;
}
