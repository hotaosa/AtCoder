#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  int r1 = -1, r2 = -1, c1 = -1, c2 = -1;
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      if (s[j] == 'o') {
        if (r1 == -1) { r1 = i; c1 = j; }
        else { r2 = i; c2 = j; }
      }
    }
  }
  cout << abs(r1 - r2) + abs(c1 - c2) << endl;
  return 0;
}
