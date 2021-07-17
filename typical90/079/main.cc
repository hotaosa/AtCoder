#include <iostream>
#include <vector>

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<long long> > a(h, std::vector<long long>(w));
  std::vector<std::vector<long long> > b(h, std::vector<long long>(w));

  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) std::cin >> a[i][j];
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) std::cin >> b[i][j];

  std::vector<int> dr = {0, 1, 0, 1};
  std::vector<int> dc = {0, 0, 1, 1};

  long long res = 0LL;
  for (int i = 0; i < h - 1; ++i) {
    for (int j = 0; j < w - 1; ++j) {
      long long diff = b[i][j] - a[i][j];
      res += std::abs(diff);
      for (int k = 0; k < 4; ++k) a[i + dr[k]][j + dc[k]] += diff;
    }
  }

  bool possible = true;
  for (int i = 0; i < h; ++i) if (a[i][w - 1] != b[i][w - 1]) possible = false;
  for (int j = 0; j < w; ++j) if (a[h - 1][j] != b[h - 1][j]) possible = false;

  if (possible) std::cout << "Yes" << std::endl << res << std::endl;
  else std::cout << "No" << std::endl;
  return 0;  
}
