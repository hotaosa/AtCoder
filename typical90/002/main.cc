#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool rightParentheses(std::string s) {
  int n = (int)s.length();
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') ++l;
    else {
      ++r;
      if (r > l) return false;
    }
  }
  if (l == r) return true;
  else return false;
}

int main() {
  int n;
  std::cin >> n;
  if (n & 1) return 0;
  std::vector<std::string> res;
  for (int bit = 0; bit < (1 << n); ++bit) {
    std::string s = "";
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) s += '(';
      else s += ')';
    }
    if (rightParentheses(s)) res.push_back(s);
  }
  std::sort(res.begin(), res.end());
  res.erase(std::unique(res.begin(), res.end()), res.end());
  for (std::string op : res) std::cout << op << std::endl;
  return 0;
}
