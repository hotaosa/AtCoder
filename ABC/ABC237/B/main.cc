#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int> > res(w, vector<int>(h));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) cin >> res[j][i];
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) cout << res[i][j] << " ";
    cout << endl;
  }
  return 0;
}
