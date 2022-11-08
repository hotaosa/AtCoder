#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  const int SIZE = 1501;
  vector<vector<int> > cnt(SIZE, vector<int>(SIZE, 0));
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ++cnt[x][y];
  }

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

  auto func = [&](int x1, int y1, int x2, int y2) -> int {
    return cnt[x2][y2] - cnt[x2][y1 - 1] - cnt[x1 - 1][y2] + cnt[x1 - 1][y1 - 1];
  };

  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << func(a, b, c, d) << endl;    
  }
  
  return 0;
}
