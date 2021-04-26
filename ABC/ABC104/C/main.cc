#include <iostream>
#include <vector>

int main() {
  int d, g;
  std::cin >> d >> g;
  std::vector<int> p(d), c(d);
  for (int i = 0; i < d; ++i) std::cin >> p[i] >> c[i];

  int res = 1 << 30;
  for (int bit = 0; bit < (1 << d); ++bit) {
    int cnt = 0, score = 0;
    for (int i = 0; i < d; ++i) {
      if (bit & (1 << i)) {
        cnt += p[i];
        score += p[i] * (i + 1) * 100;
        score += c[i];
      }
    }
    if (score < g) {
      int prob = d - 1;
      while (bit & (1 << prob)) --prob;
      if (prob < 0) continue;
      if (score + p[prob] * (prob + 1) * 100 < g) continue;
      cnt += (g - score + (prob + 1) * 100 - 1) / ((prob + 1) * 100);
    }
    res = std::min(res, cnt);
  }
  std::cout << res << std::endl;
  return 0;  
}
