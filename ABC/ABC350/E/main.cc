#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n, a, x, y;
  cin >> n >> a >> x >> y;

  map<ll, double> mp;
  auto Solve = [&](auto Solve, ll k) -> double {
    if (k == 0LL) return 0.0;
    if (mp.count(k)) return mp[k];
    double res1 = Solve(Solve, k / a) + x;
    double res2 = 0.0;
    for (ll i = 2; i <= 6; ++i) {
      res2 += Solve(Solve, k / i);
    }
    res2 = res2 / 5.0 + y * 1.2;
    return mp[k] = min(res1, res2);
  };

  cout << fixed << setprecision(10) << Solve(Solve, n) << endl;
  return 0;
}