#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::vector<int> o, x;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'o') o.push_back(i);
    else x.push_back(i);
  }

  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'o') {
      auto p = std::lower_bound(x.begin(), x.end(), i);
      if (p != x.end()) res += n - (*p);
    } else {
      auto p = std::lower_bound(o.begin(), o.end(), i);
      if (p != o.end()) res += n - (*p);
    }
  }
  
  std::cout << res << std::endl;
  return 0;  
}
