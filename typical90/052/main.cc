#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  cin >> n;

  mint res = 1;
  for (int i = 0; i < n; ++i) {
    mint sum = 0;
    for (int j = 0; j < 6; ++j) {
      int a;
      cin >> a;
      sum += a;
    }
    res *= sum;
  }
  cout << res.val() << endl;  
  return 0;
}
