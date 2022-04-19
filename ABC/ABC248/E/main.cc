#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<long long, long long> > points(n);
  for (int i = 0; i < n; ++i) cin >> points[i].first >> points[i].second;

  if (k == 1) { cout << "Infinity" << endl; return 0; }

  set<vector<int> > se;
  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      vector<int> cur = {i, j};
      int dx1 = points[j].first - points[i].first;
      int dy1 = points[j].second - points[i].second;
      for (int p = 0; p < n; ++p) {
        if (p == i || p == j) continue;
        int dx2 = points[p].first - points[j].first;
        int dy2 = points[p].second - points[j].second;
        if (dx1 * dy2 == dx2 * dy1) cur.push_back(p);
      }
      if ((int)cur.size() >= k) {
        sort(cur.begin(), cur.end());
        if (se.insert(cur).second) ++res;
      }
    }
  }
  cout << res << endl;
  return 0;
}
