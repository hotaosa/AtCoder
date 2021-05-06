#include <iostream>
#include <string>
#include <vector>

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<bool> > messy(h, std::vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) if (s[j] == '#') messy[i][j] = true;
  }

  int res = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (messy[i][j]) continue;
      if (i + 1 < h && !messy[i + 1][j]) ++res;
      if (j + 1 < w && !messy[i][j + 1]) ++res;
    }
  }

  std::cout << res << std::endl;
  return 0;
}
