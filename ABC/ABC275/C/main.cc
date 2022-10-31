#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  bool exist[9][9];
  for (int i = 0; i < 9; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < 9; ++j) exist[i][j] = s[j] == '#';
  }

  int res = 0;
  for (int r1 = 0; r1 < 9; ++r1) {
    for (int c1 = 0; c1 < 8; ++c1) {
      if (!exist[r1][c1]) continue;
      for (int r2 = r1; r2 < 9; ++r2) {
        for (int c2 = c1 + 1; c2 < 9; ++c2) {
          if (!exist[r2][c2]) continue;
          int r3 = r2 + c2 - c1;
          int c3 = c2 + r1 - r2;
          if (r3 < 0 || r3 >= 9 || c3 < 0 || c3 >= 9 || !exist[r3][c3]) continue;
          int r4 = r3 + c3 - c2;
          int c4 = c3 + r2 - r3;
          if (r4 < 0 || r4 >= 9 || c4 < 0 || c4 >= 9 || !exist[r4][c4]) continue;
          ++res;
        }
      }
    }
  }
  cout << res << endl;  
  return 0;
}
