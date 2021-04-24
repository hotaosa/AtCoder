#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  
  std::vector<std::vector<int>> tot(2, std::vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) tot[j][i] = tot[j][i - 1];
    int c, p;
    std::cin >> c >> p;
    --c;
    tot[c][i] += p;    
  }

  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    std::cin >> l >> r;
    int res1 = tot[0][r] - tot[0][l - 1];
    int res2 = tot[1][r] - tot[1][l - 1];
    std::cout << res1 << " " << res2 << std::endl;
  }

  return 0;
}
