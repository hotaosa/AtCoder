#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, r, c;
  cin >> h >> w >> r >> c;

  int res = 4;
  if (r == 1) --res;
  if (r == h) --res;
  if (c == 1) --res;
  if (c == w) --res;
  cout << res << endl;
  return 0;
}
