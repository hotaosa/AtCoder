#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<char> > v(4, std::vector<char>(4));
  for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) std::cin >> v[i][j];

  for (int i = 3; i >= 0; --i) {
    for (int j = 3; j >= 0; --j) {
      std::cout << v[i][j];
      if (j > 0) std::cout << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
