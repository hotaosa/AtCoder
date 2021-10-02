#include <iostream>
#include <string>
#include <vector>

int main() {
  int n;
  std::string s, t;
  std::cin >> n >> s >> t;

  std::vector<int> vs, vt;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') vs.push_back(i);
    if (t[i] == '0') vt.push_back(i);
  }

  if (vs.size() != vt.size()) {
    std::cout << "-1" << std::endl;
    return 0;
  }

  int res = 0;
  for (int i = 0; i < (int)vs.size(); ++i) if (vs[i] != vt[i]) ++res;
  std::cout << res << std::endl;  
  return 0;  
}
