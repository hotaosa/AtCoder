#include <iostream>
#include <string>
#include <vector>

int main() {
  int h, w;
  std::cin >> h >> w;
  
  if (h > 4 || w > 4) return 0;
  std::vector<int> white;
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) {
      if (s[j] == '.') white.push_back(i * w + j);
    }
  }

  auto judge = [&](int i, int j) -> bool {
    int r1 = i / w, c1 = i % w;
    int r2 = j / w, c2 = j % w;
    if (std::max(r1 - r2, r2 - r1) > 1) return true;
    if (std::max(c1 - c2, c2 - c1) > 1) return true;
    return false;
  };

  int res = 0;
  for (int bit = 0; bit < (1 << (int)white.size()); ++bit) {
    std::vector<int> king;
    for (int i = 0; i < (int)white.size(); ++i) if (bit & (1 << i)) king.push_back(white[i]);
    bool is_ok = true;
    for (int i = 0; i < (int)king.size() - 1; ++i) {
      for (int j = i + 1; j < (int)king.size(); ++j) {
        is_ok &= judge(king[i], king[j]);
      }
    }
    if (is_ok) ++res;
  }

  std::cout << res << std::endl;
  return 0;
}
