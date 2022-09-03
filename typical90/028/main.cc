#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  const int SIZE = 1002;
  vector<vector<int> > cnt(SIZE, vector<int>(SIZE, 0));
  for (int i = 0; i < n; ++i) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ++cnt[r1][c1];
    --cnt[r1][c2];
    --cnt[r2][c1];
    ++cnt[r2][c2];
  }

  vector<int> res(n + 1, 0);
  for (int r = 0; r < SIZE; ++r) for (int c = 1; c < SIZE; ++c) cnt[r][c] += cnt[r][c - 1];
  for (int c = 0; c < SIZE; ++c) for (int r = 1; r < SIZE; ++r) cnt[r][c] += cnt[r - 1][c];
  for (int r = 0; r < SIZE; ++r) for (int c = 0; c < SIZE; ++c) ++res[cnt[r][c]];

  for (int i = 1; i <= n; ++i) cout << res[i] << endl;
  return 0;
}
