#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> h(n);
  for (auto &e : h) cin >> e;

  ll res = 0;
  for (auto x : h) {
    while (x > 0 && res % 3) {
      x -= (++res % 3 ? 1 : 3);
    }
    if (x > 0) {
      res += x / 5 * 3 + min(3LL, x % 5);
    }
  }

  cout << res << endl;
  return 0;
}