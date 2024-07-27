#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;
using ll = long long;

bool IncludesZero(const string &s) {
  return find(begin(s), end(s), '0') != end(s);
}

bool IsPalindrome(const string &s) {
  for (int l = 0, r = size(s) - 1; l < r; ++l, --r) {
    if (s[l] != s[r]) return false;
  }
  return true;
}

string MemRec(map<ll, string> &mem, ll x) {
  if (mem.count(x)) return mem[x];
  string sx = to_string(x);
  if (!IncludesZero(sx) && IsPalindrome(sx)) {
    return mem[x] = sx;
  }

  for (ll y = 2; y * y <= x; ++y) {
    string sy = to_string(y);
    if (x % y || IncludesZero(sy)) continue;
    string sz = sy;
    reverse(begin(sz), end(sz));
    ll z = stoll(sz);

    if (x / y % z == 0 && MemRec(mem, x / y / z) != "-1") {
      return mem[x] = sy + "*" + MemRec(mem, x / y / z) + "*" + sz;
    }
  }

  return "-1";
}

int main() {
  ll n;
  cin >> n;
  map<ll, string> mp;
  cout << MemRec(mp, n) << endl;
  return 0;
}