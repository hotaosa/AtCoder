#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  cin >> n;

  vector<mint> fib(n + 1);
  fib[1] = fib[2] = 1;
  for (int i = 3; i <= n; ++i) fib[i] = fib[i - 1] + fib[i - 2];

  cout << fib[n].val() << endl;
  return 0;
}
