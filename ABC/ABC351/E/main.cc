#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll CalcSum(const vector<ll> &vec) {
  auto v = vec;
  sort(begin(v), end(v));
  ll ret = 0, sum = 0;
  for (int i = 0; i < (int)size(v); ++i) {
    ret += v[i] * i - sum;
    sum += v[i];
  }
  return ret;
}

int main() {
  int n;
  cin >> n;

  vector<ll> ox, oy, ex, ey;
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    if ((x + y) & 1) {
      ox.emplace_back(x + y);
      oy.emplace_back(x - y);
    } else {
      ex.emplace_back(x + y);
      ey.emplace_back(x - y);
    }
  }

  ll res = CalcSum(ox) + CalcSum(oy) + CalcSum(ex) + CalcSum(ey);
  cout << res / 2 << endl;
  return 0;
}