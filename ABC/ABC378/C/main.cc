#include <iostream>
#include <unordered_map>

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<int, int> mp;

  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    int res = (mp.contains(a) ? mp[a] : -1);
    std::cout << res << " ";
    mp[a] = i + 1;
  }
  std::cout << "\n";

  return 0;
}