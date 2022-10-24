#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, r, c, n;
  cin >> h >> w >> r >> c >> n;
  --r; --c;

  map<int, set<int> > walls_r, walls_c;
  for (int i = 0; i < n; ++i) {
    int ri, ci;
    cin >> ri >> ci;
    walls_r[--ri].insert(--ci);
    walls_c[ci].insert(ri);
  }

  auto move = [&](char d, int l) -> void {
    if (d == 'U') {
      auto p = walls_c[c].lower_bound(r);
      if (p == walls_c[c].begin()) r = max(0, r - l);
      else r = max(*(--p) + 1, r - l);
    } else if (d == 'D') {
      auto p = walls_c[c].upper_bound(r);
      if (p == walls_c[c].end()) r = min(h - 1, r + l);
      else r = min(*p - 1, r + l);
    } else if (d == 'L') {
      auto p = walls_r[r].lower_bound(c);
      if (p == walls_r[r].begin()) c = max(0, c - l);
      else c = max(*(--p) + 1, c - l);
    } else {
      auto p = walls_r[r].upper_bound(c);
      if (p == walls_r[r].end()) c = min(w - 1, c + l);
      else c = min(*p - 1, c + l);
    }
  };

  int q;
  cin >> q;
  while (q--) {
    char d;
    int l;
    cin >> d >> l;
    move(d, l);
    cout << r + 1 << " " << c + 1 << endl;
  }  
  return 0;
}
