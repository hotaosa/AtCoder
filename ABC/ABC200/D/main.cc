#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  for (int i = 0; i < n; ++i) {
    int num;
    std::cin >> num;
    a.push_back(num % 200);
  }

  bool exist = false;
  n = std::min(n, 8);
  std::vector<int> b, c;
  for (int bitb = 1; bitb < (1 << n) && !exist; ++bitb) {
    b.clear();
    int sumb = 0;
    for (int i = 0; i < n; ++i) {
      if (bitb & (1 << i)) {
        b.push_back(i + 1);
        sumb = (sumb + a[i]) % 200;
      }
    }
    for (int bitc = 1; bitc < (1 << n) && !exist; ++bitc) {
      if (bitc == bitb) continue;
      c.clear();
      int sumc = 0;
      for (int i = 0; i < n; ++i) {
        if (bitc & (1 << i)) {
          c.push_back(i + 1);
          sumc = (sumc + a[i]) % 200;
        }
      }
      if (sumb == sumc) exist = true;
    }
  }

  if (exist) {
    std::cout << "Yes" << std::endl;
    std::cout << b.size() << " ";
    for (int res : b) std::cout << res << " ";
    std::cout << std::endl;
    std::cout << c.size() << " ";
    for (int res : c) std::cout << res << " ";
    std::cout << std::endl;
  } else std::cout << "No" << std::endl;
  return 0;
}
