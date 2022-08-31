#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  long long n, k;  
  cin >> n >> k;
  if (n == 1) { cout << k << endl; return 0; }

  mint kk = k;
  mint res = kk * (kk - 1) * (kk - 2).pow(n - 2);
  cout << res.val() << endl;  
  return 0;
}
