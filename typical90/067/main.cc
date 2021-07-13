#include <iostream>
#include <string>
#include <algorithm>

std::string translate(std::string s) {
  int len = s.length();
  long long base = 1LL;
  long long num = 0LL;
  for (int i = len - 1; i >= 0; --i) {
    num += (s[i] - '0') * base;
    base *= 8;
  }
  std::string res = "";
  while (num) {
    res += '0' + (num % 9);
    num /= 9;
  }
  for (int i = 0; i < (int)res.length(); ++i) if (res[i] == '8') res[i] = '5';
  std::reverse(res.begin(), res.end());
  return res;
}

int main() {
  std::string s;
  int k;
  std::cin >> s >> k;

  if (s.length() == 1 && s[0] - '0' < 8) { std::cout << s << std::endl; return 0; }

  for (int i = 0; i < k; ++i) s = translate(s);
  std::cout << s << std::endl;
  return 0;  
}
