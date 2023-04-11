#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n, k;
  cin >> n >> k;
  ++k;

  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  set<long long> se = {0};
  long long res = 0;
  while (k--) {
    auto p = se.begin();
    res = *p;
    for (auto ai : a) se.insert(*p + ai);
    se.erase(p);
  }

  cout << res << endl;
  return 0;
}
