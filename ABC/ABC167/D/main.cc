#include <iostream>
#include <vector>

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  int m = 2;
  long long kk = k;
  while (kk) {
    ++m;
    kk >>= 1;
  }

  std::vector<std::vector<int> > db(m, std::vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    db[0][i] = --a;
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      db[i][j] = db[i - 1][db[i - 1][j]];
    }
  }

  int res = 0;
  for (int i = 0; i < m; ++i) {
    if (k & (1LL << i)) res = db[i][res];
  }

  std::cout << res + 1 << std::endl;
  return 0;  
}
