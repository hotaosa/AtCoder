#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

mint func(long long x, map<long long, mint> &memo) {
  if (memo[x].val()) return memo[x];
  else return memo[x] = func(x / 2, memo) * func((x + 1) / 2, memo);
}

int main() {
  long long x;
  cin >> x;
  map<long long, mint> memo;
  memo[1] = 1;
  memo[2] = 2;
  memo[3] = 3;
  cout << func(x, memo).val() << endl;  
  return 0;
}
