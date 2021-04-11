#include <iostream>
#include <string>

int main() {
  int n, m;
  std::cin >> n >> m;
  long long odd = 0LL, even = 0LL;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for (int j = 0; j < m; ++j) if (s[j] == '1') ++cnt;
    ++(cnt & 1 ? odd : even);
  }
  std::cout << odd * even << std::endl;
  return 0;
}
