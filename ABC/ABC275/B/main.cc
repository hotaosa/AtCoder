#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  const long long mod = 998244353;
  vector<long long> v(6);
  for (auto &p : v) { cin >> p; p %= mod; }
  cout << (v[0] * v[1] % mod * v[2] % mod - v[3] * v[4] % mod * v[5] % mod + mod) % mod << endl;
  return 0;
}
