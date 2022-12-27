#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  int digit = 0;
  while ((1 << digit) < n) ++digit;

  vector<vector<int> > table(n + 1, vector<int>(digit + 1, -1));

  vector<pair<int, int> > vp;
  for (int i = 1; i <= n; ++i) vp.emplace_back(i, i);

  for (int l = 1; l < n; ++l) {
    for (int shift = 0; l + (1 << shift) <= n; ++shift) {
      int r = l + (1 << shift);
      table[l][shift] = vp.size();
      vp.emplace_back(l, r);
    }
  }

  cout << vp.size() << endl;
  for (auto [l, r] : vp) cout << l << " " << r << endl;

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << l << " " << l << endl;
    } else {
      int sl = 0, sr = 0;
      while (l + (1 << (sl + 1)) <= r) ++sl;
      while (r - (1 << (sr + 1)) >= l) ++sr;
      int id1 = table[l][sl] + 1;
      int id2 = table[r - (1 << sr)][sr] + 1;
      cout << id1 << " " << id2 << endl;
    }
  }

  return 0;
}
