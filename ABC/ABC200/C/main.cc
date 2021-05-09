#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> cnt(200, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    ++cnt[a % 200];
  }

  long long res = 0LL;
  for (int num : cnt) {
    res += num * (num - 1LL) / 2LL;
  }
  std::cout << res << std::endl;
  return 0;
}
