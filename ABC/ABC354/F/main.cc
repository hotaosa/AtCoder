#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;

  auto b = a;
  reverse(begin(b), end(b));
  for (auto &bb : b) bb = -bb;

  auto Func = [&](vector<int> v) -> vector<int> {
    vector<int> dp, ret(n);
    for (int i = 0; i < n; ++i) {
      auto it = lower_bound(begin(dp), end(dp), v[i]);
      ret[i] = it - begin(dp) + 1;
      if (it == end(dp)) {
        dp.emplace_back(v[i]);
      } else {
        *it = v[i];
      }
    }
    return ret;
  };

  auto lis_l = Func(a);
  auto lis_r = Func(b);
  reverse(begin(lis_r), end(lis_r));
  int lis = *max_element(begin(lis_l), end(lis_l));

  vector<int> res;
  for (int i = 0; i < n; ++i) {
    if (lis_l[i] + lis_r[i] == lis + 1) {
      res.emplace_back(i);
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    auto res = Solve();
    cout << size(res) << endl;
    for (auto r : res) cout << r + 1 << " ";
    cout << endl;
  }
  return 0;
}