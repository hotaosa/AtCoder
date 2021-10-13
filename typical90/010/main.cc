#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > score(2, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    int c, p;
    std::cin >> c >> p;
    score[--c][i] = p;
  }
  for (int i = 0; i < 2; ++i) for (int j = 1; j < n; ++j) score[i][j] += score[i][j - 1];

  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    --l;
    --r;
    std::cout << score[0][r] - (l > 0 ? score[0][l - 1] : 0) << " ";
    std::cout << score[1][r] - (l > 0 ? score[1][l - 1] : 0) << std::endl;
  }
  return 0;  
}
