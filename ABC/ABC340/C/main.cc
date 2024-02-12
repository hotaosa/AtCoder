#include <iostream>
#include <map>

using namespace std;
using ll = long long;

ll Solve(ll n, map<ll, ll> &mp) {
  if (mp.count(n) == 0) {
    mp[n] = n + Solve(n / 2, mp) + Solve((n + 1) / 2, mp);
  }
  return mp[n];
}

int main() {
  ll n;
  cin >> n;
  map<ll, ll> mp;
  mp[1] = 0;
  cout << Solve(n, mp) << endl;
  return 0;
}
