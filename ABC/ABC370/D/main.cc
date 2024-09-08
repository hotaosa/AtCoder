#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int h, w, q;
  cin >> h >> w >> q;

  vector<set<int>> sr(h), sc(w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      sr[i].insert(j);
      sc[j].insert(i);
    }
  }

  while (q--) {
    int r, c;
    cin >> r >> c;

    if (sr[--r].count(--c)) {
      sr[r].erase(c);
      sc[c].erase(r);
    } else {
      {
        auto it = sr[r].lower_bound(c);
        if (it != begin(sr[r])) {
          sc[*prev(it)].erase(r);
          sr[r].erase(prev(it));
        }
        if (it != end(sr[r])) {
          sc[*it].erase(r);
          sr[r].erase(it);
        }
      }
      {
        auto it = sc[c].lower_bound(r);
        if (it != begin(sc[c])) {
          sr[*prev(it)].erase(c);
          sc[c].erase(prev(it));
        }
        if (it != end(sc[c])) {
          sr[*it].erase(c);
          sc[c].erase(it);
        }
      }
    }
  }

  int res = 0;
  for (const auto &s : sr) {
    res += size(s);
  }
  cout << res << endl;

  return 0;
}