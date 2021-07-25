#include <iostream>
#include <vector>
#include <string>
#include <set>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<bool> is_white(n * n, false);
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < n; ++j) if (s[j] == '.') is_white[i * n + j] = true;
  }

  std::set<unsigned long long> se;
  for (int i = 0; i < n * n; ++i) if (is_white[i]) se.insert(1ULL << i);
  for (; k > 1; --k) {
    std::set<unsigned long long> se2;
    for (auto picked : se) {
      for (int i = 0; i < n * n; ++i) {
        if (!(picked & (1ULL << i)) || !is_white[i]) continue;
        std::vector<int> next;
        if (i % n > 0 && is_white[i - 1]) next.push_back(i - 1);
        if (i % n < n - 1 && is_white[i + 1]) next.push_back(i + 1);
        if (i >= n && is_white[i - n]) next.push_back(i - n);
        if (i < n * n - n && is_white[i + n]) next.push_back(i + n);
        for (int nv : next) {
          if (picked & (1ULL << nv)) continue;
          se2.insert(picked | (1ULL << nv));
        }
      }
    }
    se = se2;
  }

  std::cout << se.size() << std::endl;
  return 0;
}
