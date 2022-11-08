#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  const int size = 1502;
  vector<vector<int> > cnt(size, vector<int>(size, 0));

  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ++cnt[x1][y1];
    --cnt[x1][y2];
    --cnt[x2][y1];
    ++cnt[x2][y2];
  }  

  for (int i = 0; i < size; ++i) {
    for (int j = 1; j < size; ++j) {
      cnt[i][j] += cnt[i][j - 1];
    }
  }

  int res = 0;
  for (int j = 0; j < size; ++j) {
    for (int i = 0; i < size; ++i) {
      if (i > 0) cnt[i][j] += cnt[i - 1][j];
      if (cnt[i][j] > 0) ++res;
    }
  }
  
  cout << res << endl;  
  return 0;
}
