#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    int p;
    std::cin >> p;
    res[--p] = i + 1;
  }

  for (int r : res) std::cout << r << " ";
  std::cout << std::endl;
  return 0;
}
