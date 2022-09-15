#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;

  vector<long long> p(a), q(b), r(c);
  for (auto &it : p) cin >> it;
  for (auto &it : q) cin >> it;
  for (auto &it : r) cin >> it;

  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  for (int i = 0; i < x; ++i) r.push_back(p[i]);
  for (int i = 0; i < y; ++i) r.push_back(q[i]);

  sort(r.rbegin(), r.rend());
  long long res = 0;
  for (int i = 0; i < x + y; ++i) res += r[i];
  cout << res << endl;  
  return 0;
}
