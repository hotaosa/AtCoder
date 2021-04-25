#include <iostream>
#include <vector>

int main() {
  const int SIZ = 55555;
  
  int n;
  std::cin >> n;

  std::vector<bool> is_prime(SIZ + 1, true);
  std::vector<int> vec_prime;
  is_prime[0] = false;
  is_prime[1] = false;

  for (int i = 2; i * i <= SIZ; ++i) {
    if (is_prime[i]) {
      for (int j = 2; i * j <= SIZ; ++j) is_prime[i * j] = false;
    }
  }

  int cnt = 0;
  for (int i = 2; i < SIZ; ++i) {
    if (is_prime[i] && i % 5 == 1) { std::cout << i << " "; ++cnt; }
    if (cnt == n) break;
  }
  std::cout << std::endl;
  return 0;
}
