#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;

  int cnt = 1;
  map<int, int> mp;
  for (auto &p : a) {
    if (!mp.count(p)) mp[p] = cnt++;
    p = mp[p];
  }
  for (auto &p : b) {
    if (!mp.count(p)) mp[p] = cnt++;
    p = mp[p];
  }
  vector<int> mx_a(n);
  mx_a[0] = a[0];
  for (int i = 1; i < n; ++i) mx_a[i] = max(mx_a[i - 1], a[i]);

  int q;
  cin >> q;
  vector<tuple<int, int, int> > query;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    query.emplace_back(--y, --x, i);
  }
  sort(query.begin(), query.end());

  vector<bool> res(q, false);
  set<int> se;
  int pos = 0;
  for (int i = 0; i < q; ++i) {
    int x = get<1>(query[i]);
    int y = get<0>(query[i]);
    int id = get<2>(query[i]);
    while (pos <= y) se.insert(b[pos++]);
    if ((int)se.size() == mx_a[x] && *se.rbegin() == mx_a[x]) res[id] = true;
  }

  for (int i = 0; i < q; ++i) cout << (res[i] ? "Yes" : "No" ) << endl;  
  return 0;
}
