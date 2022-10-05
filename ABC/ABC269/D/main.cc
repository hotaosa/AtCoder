#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool adjacent(int x1, int y1, int x2, int y2) {
  int dx = x1 - x2, dy = y1 - y2;
  if (max(abs(dx), abs(dy)) >= 2) return false;
  if (dx + dy == 0) return false;
  return abs(dx + dy) <= 2;
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  atcoder::dsu uf(n);
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (adjacent(x[i], y[i], x[j], y[j])) uf.merge(i, j);
    }
  }

  int res = 0;
  for (int i = 0; i < n; ++i) if (uf.leader(i) == i) ++res;
  cout << res << endl;  
  return 0;
}
