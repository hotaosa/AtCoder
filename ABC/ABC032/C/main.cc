#include <iostream>
#include <vector>

int main() {
  int n;
  long long k;
  std::cin >> n >> k;
  std::vector<long long> s(n);
  bool exist_zero = false;
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
    if (s[i] == 0LL) exist_zero = true;
  }
  if (exist_zero) { std::cout << n << std::endl; return 0; }
  
  int res = 0, l = -1, r = 0;
  long long cur = 1LL;
  while (r < n) {
    cur *= s[r];
    while (cur > k && r > l) cur /= s[++l];
    res = std::max(res, r - l);
    ++r;
  }
  
  std::cout << res << std::endl;
  return 0;
}
