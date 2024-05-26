#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> vp;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    vp.emplace_back(l, 0);
    vp.emplace_back(r, 1);
  }
  sort(begin(vp), end(vp));

  ll cur = 0, res = 0;
  for (auto &[_, v] : vp) {
    if (v) {
      --cur;
      res += cur;
    } else {
      ++cur;
    }
  }
  cout << res << endl;
  return 0;
}