#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &e : a) std::cin >> e;
  for (auto &e : b) std::cin >> e;

  std::cout << *std::max_element(std::begin(a), std::end(a)) +
                   *std::max_element(std::begin(b), std::end(b))
            << std::endl;

  return 0;
}