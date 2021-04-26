#include <iostream>
#include <string>

long long calc(std::string s, int bit) {
  int n = (int)s.length();
  long long res = 0LL, cur = (long long)(s[0] - '0');
  for (int i = 0; i < n - 1; ++i) {
    if (bit & (1 << i)) { res += cur; cur = (long long)(s[i + 1] - '0'); }
    else {
      cur *= 10LL;
      cur += (long long)(s[i + 1] - '0');
    }
  }
  res += cur;
  return res;
}

int main() {
  std::string s;
  std::cin >> s;
  int n = (int)s.length();
  --n;
  long long res = 0LL;
  for (int bit = 0; bit < (1 << n); ++bit) {
    res += calc(s, bit);
  }
  std::cout << res << std::endl;
  return 0;
}
