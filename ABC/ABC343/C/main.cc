#include <iostream>
#include <string>

using namespace std;
using ll = long long;

bool IsPalindrome(ll x) {
  string s = to_string(x);
  for (int l = 0, r = (int)s.size() - 1; l < r; ++l, --r) {
    if (s[l] != s[r]) {
      return false;
    }
  }
  return true;
}

int main() {
  ll n;
  cin >> n;

  ll res = 0;
  for (ll x = 1; x * x * x <= n; ++x) {
    if (IsPalindrome(x * x * x)) {
      res = x * x * x;
    }
  }

  cout << res << endl;
  return 0;
}