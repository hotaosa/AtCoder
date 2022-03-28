#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > ab(n), cd(m);
  for (int i = 0; i < n; ++i) cin >> ab[i].first;
  for (int i = 0; i < n; ++i) cin >> ab[i].second;
  for (int i = 0; i < m; ++i) cin >> cd[i].first;
  for (int i = 0; i < m; ++i) cin >> cd[i].second;
  sort(ab.begin(), ab.end());
  sort(cd.begin(), cd.end());

  multiset<int> se;
  auto pbox = cd.rbegin();
  for (auto pchoco = ab.rbegin(); pchoco != ab.rend(); ++pchoco) {
    while (pbox != cd.rend() && pbox->first >= pchoco->first) {
      se.insert(pbox->second);
      ++pbox;
    }
    auto p = se.lower_bound(pchoco->second);
    if (p == se.end()) { cout << "No" << endl; return 0; }
    se.erase(p);
  }

  cout << "Yes" << endl;  
  return 0;
}
