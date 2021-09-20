#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
  std::string x;
  int n;
  std::cin >> x >> n;
  std::vector<std::string> vs(n);

  std::map<char, char> ma1, ma2;
  for (int i = 0; i < 26; ++i) {
    ma1[x[i]] = i;
    ma2['a' + i] = x[i];
  }

  auto convert = [&](std::string t) -> std::string {
    std::string ret = "";
    for (char c : t) ret += ma1[c];
    return ret;
  };

  auto decode = [&](std::string t) -> std::string {
    std::string res = "";
    for (char c : t) res += ma2[c];
    return ret;
  };
  
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    vs[i] = convert(s);
  }
  std::sort(vs.begin(), vs.end());
  for (std::string res : vs) std::cout << decode(res) << std::endl;
  return 0;  
}
