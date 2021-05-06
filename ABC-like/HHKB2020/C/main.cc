#include <iostream>
#include <vector>

int main() {
  std::vector<bool> exist(200001, false);
  int n;
  std::cin >> n;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int p;
    std::cin >> p;
    exist[p] = true;
    while (exist[cur]) ++cur;
    std::cout << cur << std::endl;
  }
  return 0;  
}
