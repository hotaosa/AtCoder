#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll lsm = n / gcd(n, m) * m;

  auto Judge = [&](ll x) -> bool { return x / n + x / m - x / lsm * 2 >= k; };

  ll l = 0, r = 1LL << 60;
  while (r - l > 1) {
    ll x = (l + r) >> 1;
    (Judge(x) ? r : l) = x;
  }

  cout << r << endl;
  return 0;
}