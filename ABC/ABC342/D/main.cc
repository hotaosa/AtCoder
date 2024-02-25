#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int FactXor(int x) {
  if (x == 0) return 0;
  int ret = 1;
  for (int y = 2; y * y <= x; ++y) {
    int cnt = 0;
    while (x % y == 0) {
      cnt ^= 1;
      x /= y;
    }
    if (cnt) {
      ret *= y;
    }
  }
  if (x > 1) {
    ret *= x;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  map<int, ll> mp;
  ll cnt_zero = 0, res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a == 0) {
      res += i;
      ++cnt_zero;
      continue;
    }

    a = FactXor(a);
    res += cnt_zero + mp[a]++;
  }

  cout << res << endl;
  return 0;
}
