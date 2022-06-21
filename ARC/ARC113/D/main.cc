#include <iostream>
#include <vector>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m, k;
  cin >> n >> m >> k; 

  if (min(n, m) == 1) { cout << mint(k).pow(max(n, m)).val() << endl; return 0; }
  
  mint res = 0;
  for (int a = 1; a <= k; ++a) res += mint(k - a + 1).pow(m) * (mint(a).pow(n) - mint(a - 1).pow(n));
  cout << res.val() << endl;  
  return 0;
}
