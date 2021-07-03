#include <iostream>
#include <map>

int main() {
  long long n;
  std::cin >> n;

  std::map<int, long long> ma;
  for (int i = 0; i < (int)n; ++i) {
    int a;
    std::cin >> a;
    ++ma[a];
  }

  long long res = n * (n - 1LL) / 2LL;
  for (auto m : ma) res -= m.second * (m.second - 1LL) / 2LL;
  std::cout << res << std::endl;
  return 0;  
}
