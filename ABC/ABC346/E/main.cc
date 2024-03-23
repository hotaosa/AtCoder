#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  vector<ll> siz(2);
  int m;
  cin >> siz[0] >> siz[1] >> m;

  vector<int> t(m), a(m), x(m);
  for (int i = 0; i < m; ++i) {
    cin >> t[i] >> a[i] >> x[i];
  }

  map<int, ll> mp;
  vector se(2, set<int>());
  for (int i = m - 1; i >= 0; --i) {
    if (se[--t[i]].insert(a[i]).second) {
      mp[x[i]] += siz[t[i] ^ 1] - size(se[t[i] ^ 1]);
    }
  }

  mp[0] += (siz[0] - size(se[0])) * (siz[1] - size(se[1]));
  vector<pair<int, ll>> res;
  for (auto [v, c] : mp) {
    if (c) res.emplace_back(v, c);
  }

  cout << size(res) << endl;
  for (auto [v, c] : res) {
    cout << v << " " << c << endl;
  }
  return 0;
}