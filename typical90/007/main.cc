#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  a.push_back(-1000000001);
  a.push_back(2000000001);
  sort(a.begin(), a.end());
  
  int q;
  cin >> q;
  while (q--) {
    int b;
    cin >> b;
    auto p = lower_bound(a.begin(), a.end(), b);
    int res = abs(b - *p);
    res = min(res, abs(b - *(--p)));
    cout << res << endl;
  }
  return 0;
}
