#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  const int h = n + 10, w = n + 2 * m + 10;
  vector<vector<int> > cnt(h, vector<int>(w, 0));

  auto add = [&](int r, int c, int v) -> void {
    if (r >= 0 && r < h && c >= 0 && c < w) cnt[r][c] += v;
  };

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] == 'O') {
        add(i, j, 1);
        add(i + 1, j - 2, -1);
        add(i + m + 1, j - 2, 1);
        add(i + m + 1, j, -1);
        add(i + 1, j + 2 * m, 1);
        add(i, j + 2 * m, -1);
      }
    }
  }

  for (int i = 0; i < h - 1; ++i) for (int j = 2; j < w; ++j) cnt[i + 1][j - 2] += cnt[i][j];
  for (int i = 0; i < h - 1; ++i) for (int j = 0; j < w; ++j) cnt[i + 1][j] += cnt[i][j];
  for (int i = 0; i < h; ++i) for (int j = 0; j < w - 1; ++j) cnt[i][j + 1] += cnt[i][j];

  int q;
  cin >> q;
  while (q--) {
    int r, c;
    cin >> r >> c;
    cout << cnt[--r][--c] << endl;
  }
  return 0;
}