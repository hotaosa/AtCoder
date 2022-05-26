#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, k;
  cin >> n >> k;

  mint res = 0;
  vector<mint> cnt(k + 1);
  for (int i = k; i > 0; --i) {
    mint div = mint(k / i);
    cnt[i] = div.pow(n);
    for (int j = i * 2; j <= k; j += i) cnt[i] -= cnt[j];
    res += i * cnt[i];
  }
  cout << res.val() << endl;  
  return 0;
}
