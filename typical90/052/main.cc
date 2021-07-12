#include <iostream>

int main() {
  long long MOD = 1000000007LL;
  int n;
  std::cin >> n;
  
  long long res = 1LL;
  for (int i = 0; i < n; ++i) {
    long long sum = 0LL;
    for (int i = 0; i < 6; ++i) {
      long long num;
      std::cin >> num;
      sum += num;
    }
    res = (res * sum) % MOD;
  }
  std::cout << res << std::endl;
  return 0;  
}
