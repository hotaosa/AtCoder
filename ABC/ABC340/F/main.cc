#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

pair<ll, ll> ExtGCD(ll a, ll b) {
  if (b == 0) {
    return make_pair(1, 0);
  }
  auto [y, x] = ExtGCD(b, a % b);
  y -= a / b * x;
  return make_pair(x, y);
}

int main() {
  ll x, y;
  cin >> x >> y;
  auto g = gcd(abs(x), abs(y));
  if (g > 2) {
    cout << "-1\n";
    return 0;
  }
  auto [a, b] = ExtGCD(y, -x);
  if (g == 1) {
    a *= 2;
    b *= 2;
  }

  cout << a << " " << b << endl;
  return 0;
}
