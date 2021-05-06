#include <iostream>

int main() {
  const long long MOD = 1000000007LL;
  
  int t;
  std::cin >> t;

  for (int i = 0; i < t; ++i) {
    long long n, a, b;
    std::cin >> n >> a >> b;
    long long ca = (n - a + 1) * (n - a + 1) % MOD;
    long long cb = (n - b + 1) * (n - b + 1) % MOD;
    long long overlap = (n - a + 1) * (n - b + 1) % MOD;
    if (n - a - b >= 0) overlap = ((n - a + 1) * (n - b + 1) - (n - a - b + 2) * (n - a - b + 1)) % MOD;
    overlap = overlap * overlap % MOD;
    long long res = (ca * cb - overlap) % MOD;
    if (res < 0) res += MOD;
    std::cout << res << std::endl;
  }
}
