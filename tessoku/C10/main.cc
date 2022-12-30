#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  long long w;
  cin >> w;

  mint res = 12;
  res *= mint(7).pow(w - 1);
  cout << res.val() << endl;
    
  return 0;
}
