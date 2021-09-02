#include <iostream>
#include <vector>

int main() {
  long long n;
  std::cin >> n;

  std::vector<int> res;
  while (n) {
    if (n & 1LL) {
      res.push_back(0);
      --n;
    } else {
      res.push_back(1);
      n /= 2LL;
    }
  }

  for (auto rit = res.rbegin(); rit != res.rend(); ++rit) {
    std::cout << (*rit ? 'B' : 'A');
  }
  std::cout << std::endl;
  return 0; 
}
