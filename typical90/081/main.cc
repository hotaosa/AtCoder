 #include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  const int SIZE = 5001;
  vector<vector<int> > cnt(SIZE, vector<int>(SIZE, 0));
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    ++cnt[a][b];
    if (a + k + 1 < SIZE) --cnt[a + k + 1][b];
    if (b + k + 1 < SIZE) --cnt[a][b + k + 1];
    if (a + k + 1 < SIZE && b + k + 1 < SIZE) ++cnt[a + k + 1][b + k + 1];    
  }

  int res = 0;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 1; j < SIZE; ++j) {
      cnt[i][j] += cnt[i][j - 1];
    }
  }
  for (int j = 0; j < SIZE; ++j) {
    for (int i = 1; i < SIZE; ++i) {
      cnt[i][j] += cnt[i - 1][j];
    }
  }
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      res = max(res, cnt[i][j]);
    }
  }
  cout << res << endl;  
  return 0;
}
