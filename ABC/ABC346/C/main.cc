#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main() {
  int n;
  ll k;
  cin >> n >> k;

  set<ll> se;
  ll res = k * (k + 1) / 2;
  while (n--) {
    ll a;
    cin >> a;
    if (a <= k && se.insert(a).second) {
      res -= a;
    }
  }

  cout << res << endl;
  return 0;
}