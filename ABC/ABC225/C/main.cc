#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > b(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> b[i][j];
      --b[i][j];
    }
  }
  
  bool is_rectangle = true;
  if (b[0][0] / 7 != b[0][m - 1] / 7) is_rectangle = false;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && b[i][0] != b[i - 1][0] + 7) is_rectangle = false;
    for (int j = 1; j < m; ++j) {
      if (b[i][j] != b[i][j - 1] + 1) is_rectangle = false;
    }
  }

  std::cout << (is_rectangle ? "Yes" : "No") << std::endl;
  return 0;
}
