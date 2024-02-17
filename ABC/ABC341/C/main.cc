#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h, w, n;
  string t;
  cin >> h >> w >> n >> t;
  vector<string> s(h);
  for (auto &e : s) cin >> e;

  auto Func = [&](int r, int c) -> int {
    for (auto d : t) {
      if (d == 'L') {
        --c;
      } else if (d == 'R') {
        ++c;
      } else if (d == 'U') {
        --r;
      } else {
        ++r;
      }
      if (s[r][c] == '#') return 0;
    }
    return 1;
  };

  int res = 0;
  for (int i = 1; i < h - 1; ++i) {
    for (int j = 1; j < w - 1; ++j) {
      if (s[i][j] == '#') continue;
      res += Func(i, j);
    }
  }

  cout << res << endl;
  return 0;
}