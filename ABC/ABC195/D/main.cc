#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<pair<int, int> > baggage, box;
  for (int i = 0; i < n; ++i) {
    int w, v;
    cin >> w >> v;
    baggage.emplace_back(v, w);
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    box.emplace_back(x, i);
  }

  sort(baggage.rbegin(), baggage.rend());
  sort(box.begin(), box.end());

  auto solve = [&](int l, int r) -> int {
    int res = 0;
    vector<bool> used(m, false);
    for (int i = 0; i < m; ++i) if (box[i].second >= l && box[i].second < r) used[i] = true;
    for (int i = 0; i < n; ++i) {
      int p = -1;
      for (int j = m - 1; j >= 0; --j) {
        if (!used[j] && box[j].first >= baggage[i].second) p = j;
      }
      if (p == -1) continue;
      used[p] = true;
      res += baggage[i].first;
    }
    return res;
  };
  

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << solve(--l, r) << endl;
  }  
  return 0;
}
