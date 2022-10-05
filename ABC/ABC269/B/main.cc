#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}
template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  vector<string> vs(10);
  for (auto &p : vs) cin >> p;

  int r1 = 10, r2 = -1, c1 = 10, c2 = -1;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (vs[i][j] == '#') {
        chmin(r1, i);
        chmax(r2, i);
        chmin(c1, j);
        chmax(c2, j);
      }
    }
  }
  printf("%d %d %d %d\n", r1 + 1, r2 + 1, c1 + 1, c2 + 1);  
  return 0;
}
