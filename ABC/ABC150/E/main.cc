#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (auto &p : c) cin >> p;
  sort(c.begin(), c.end(), greater<>());

  mint res = 0;
  for (int i = 0; i < n; ++i) res += (mint)(i + 2) * c[i];
  for (int i = 0; i < n - 1; ++i) res *= 4;
  cout << res.val() << endl;  
  return 0;
}
