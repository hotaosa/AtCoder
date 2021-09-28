#include <iostream>
#include <string>
#include <algorithm>

int main() {
  int k;
  std::string sa, sb;
  std::cin >> k >> sa >> sb;
  std::reverse(sa.begin(), sa.end());
  std::reverse(sb.begin(), sb.end());

  long long a = 0LL, b = 0LL;
  int la = (int)sa.length(), lb = (int)sb.length();
  long long base = 1LL;
  for (int i = 0; i < std::max(la, lb); ++i) {
    if (i < la) a += (sa[i] - '0') * base;
    if (i < lb) b += (sb[i] - '0') * base;
    base *= k;
  }

  std::cout << a * b << std::endl;
  return 0;
}
