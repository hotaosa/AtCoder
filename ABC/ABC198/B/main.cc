#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> nums;
  while (n && n % 10 == 0) n /= 10;
  while (n) {
    nums.push_back(n % 10);
    n /= 10;
  }

  bool possible = true;
  if (!nums.empty()) {
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (nums[i] != nums[nums.size() - 1 - i]) possible = false;
    }
  }

  std::cout << (possible ? "Yes" : "No") << std::endl;
  return 0;
}
