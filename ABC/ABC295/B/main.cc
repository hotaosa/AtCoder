#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int h, w;
  cin >> h >> w;

  vector<tuple<int, int, int> > vt;

  vector<string> s(h);
  for (int i = 0; i < h; ++i) {
    cin >> s[i];
    for (int j = 0; j < w; ++j) {
      if (s[i][j] >= '1' && s[i][j] <= '9') {
        vt.emplace_back(i, j, s[i][j] - '0');
      }
    }
  }

  auto Dist = [&](int r1, int c1, int r2, int c2) -> int {
    return abs(r1 - r2) + abs(c1 - c2);
  };

  auto Broken = [&](int r, int c) -> bool {
    for (auto [i, j, d] : vt) {
      if (Dist(r, c, i, j) <= d) return true;
    }
    return false;
  };

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << (Broken(i, j) ? '.' : s[i][j]);
    }
    cout << endl;
  }
  
  return 0;
}
