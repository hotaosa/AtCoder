#include <iostream>
#include <vector>

constexpr long long MOD = 998244353LL;

long long modpow(long long a, long long n) {
  long long ret = 1LL;
  while (n) {
    if (n & 1LL) ret = ret * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return ret;
}

int main() {
  std::string s;
  std::cin >> s;
  int len = (int)s.length();
  if (len == 1) { std::cout << s << std::endl; return 0; }  

  std::vector<long long> pw10(len), inv(len), coef(len);
  pw10[0] = 1LL;
  inv[0] = modpow(2LL, MOD - 2);
  coef[0] = inv[0];
  for (int i = 1; i < len; ++i) {
    pw10[i] = pw10[i - 1] * 10LL % MOD;
    inv[i] = inv[i - 1] * inv[0] % MOD;
    coef[i] = (coef[i - 1] + pw10[i] * inv[i]) % MOD;
  }

  long long res = s.back() - '0';
  for (int i = len - 2; i >= 0; --i) {
    int k = len - i;
    long long add = coef[k - 2];
    add = (add + pw10[k - 1] * inv[k - 2]) % MOD;
    res = (res + (s[i] - '0') * add) % MOD;
  }
  res = res * modpow(2LL, len - 1) % MOD;
  std::cout << res << std::endl;
  return 0;
}
