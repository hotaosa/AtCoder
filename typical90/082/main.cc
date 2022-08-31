#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  long long l, r;
  cin >> l >> r;

  long long base = 10;
  while (base <= l) base *= 10;

  mint res = 0;
  while (true) {
    long long ri = min(r, base - 1);
    mint len = to_string(l).length();
    res += len * (ri + l) * (ri - l + 1) / 2;
    if (base > r) break;
    l = base;
    if (base == (long long)1e18) base = (long long)1e18 + 1;
    else base *= 10;
  }

  cout << res.val() << endl;  
  return 0;
}
