#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> nums;
  while (n) {
    nums.push_back(n % 10);
    n /= 10;
  }
  std::sort(nums.begin(), nums.end());

  long long res = 0LL;
  do {
    for (int i = 0; i < (int)nums.size(); ++i) {
      long long a = 0LL, b = 0LL;
      for (int j = 0; j < (int)nums.size(); ++j) {
        if (j <= i) {
          a *= 10LL;
          a += nums[j];
        } else {
          b *= 10LL;
          b += nums[j];
        }
      }
      res = std::max(res, a * b);
    }
  } while (std::next_permutation(nums.begin(), nums.end()));

  std::cout << res << std::endl;
  return 0;
}
