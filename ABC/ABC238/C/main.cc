#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  long long n;
  cin >> n;

  long long l = 1, r = 0;
  mint res = 0;
  while (r != n) {
    r = min(r * 10 + 9, n);
    mint add = r - l + 1;
    add *= r - l + 2;
    add /= 2;
    res += add;
    l *= 10;
  }
  cout << res.val() << endl;
  return 0;
}
