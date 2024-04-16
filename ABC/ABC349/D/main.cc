#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> Solve(ll l, ll r) {
  vector<pair<ll, ll>> ret;
  for (int i = 0; i < 61; ++i) {
    if (l >> i & 1 && (l + (1LL << i) <= r)) {
      ret.emplace_back(l, l + (1LL << i));
      l += (1LL << i);
    }
  }
  for (int i = 60; i >= 0; --i) {
    if (l + (1LL << i) <= r) {
      ret.emplace_back(l, l + (1LL << i));
      l += (1LL << i);
    }
  }
  return ret;
}

int main() {
  ll l, r;
  cin >> l >> r;

  auto res = Solve(l, r);
  cout << size(res) << endl;
  for (auto [x, y] : res) {
    cout << x << " " << y << endl;
  }

  return 0;
}