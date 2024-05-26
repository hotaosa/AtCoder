#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a) cin >> e;
  sort(begin(a), end(a));

  ll res = 0;
  ll mod = 100000000;
  for (auto it = begin(a); it != end(a); ++it) {
    int cnt = end(a) - lower_bound(next(it), end(a), mod - *it);
    res += *it * (n - 1) - mod * cnt;
  }

  cout << res << endl;
  return 0;
}