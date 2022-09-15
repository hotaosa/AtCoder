#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

int main() {
  int n, p;
  string s;
  cin >> n >> p >> s;

  if (__gcd(10, p) != 1) {
    long long res = 0;
    for (int i = 0; i < n; ++i) if ((s[i] - '0') % p == 0) res += i + 1;
    cout << res << endl;
    return 0;
  }

  mint::set_mod(p);
  vector<int> cnt(p, 0);
  ++cnt[0];  

  long long res = 0;
  mint cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    cur += (s[i] - '0') * mint(10).pow(n - 1 - i);
    res += cnt[cur.val()];
    ++cnt[cur.val()];    
  }

  cout << res << endl;
  return 0;  
}
