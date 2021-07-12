#include <iostream>
#include <vector>

int button(int num) {
  int res = num;
  while (num) {
    res += num % 10;
    num /= 10;
  }
  return res % 100000;
}

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  std::vector<int> used(100001, -1);
  std::vector<int> nums;
  used[n] = true;
  nums.push_back(n);

  int cnt = 0;
  for (long long i = 0; i < k; ++i) {
    n = button(n);
    ++cnt;
    if (used[n] != -1) {
      if (cnt == 1) { std::cout << n << std::endl; return 0; }
      int loop_len = cnt - used[n];
      std::cout << nums[(k - cnt) % loop_len + used[n]] << std::endl;
      return 0;
    }
    used[n] = cnt;
    nums.push_back(n);
  }

  std::cout << n << std::endl;
  return 0;  
}
