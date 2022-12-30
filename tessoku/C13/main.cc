#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, p;  
  cin >> n >> p;

  map<int, long long> mp;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    ++mp[mint(a).val()];
  }

  if (p == 0) {
    if (mp[0] > 0) {
      cout << mp[0] * (mp[0] - 1) / 2 + mp[0] * (n - mp[0]) << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }
  
  long long res = 0;
  for (auto [x, cnt] : mp) {
    if (x == 0) continue;
    int y = (p / mint(x)).val();
    if (x == y) {
      res += mp[x] * (mp[x] - 1);
    } else {
      res += mp[x] * mp[y];
    }
  }
  res /= 2;

  cout << res << endl;  
  return 0;
}
