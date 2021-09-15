#include <iostream>
#include <vector>
#include <set>

int func(std::vector<std::vector<int> > &grundy, int w, int b) {
  if (grundy[w][b] != -1) return grundy[w][b];
  std::set<int> se;
  if (w > 0) se.insert(func(grundy, w - 1, b + w));
  if (b > 1) for (int i = 1; i <= b / 2; ++i) se.insert(func(grundy, w, b - i));
  int res = -1;
  while (se.count(++res)) { }
  return grundy[w][b] = res;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> w(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> w[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];

  std::vector<std::vector<int> > grundy(51, std::vector<int>(1501, -1));
  grundy[0][0] = grundy[0][1] = 0;

  int res = 0;
  for (int i = 0; i < n; ++i) res ^= func(grundy, w[i], b[i]);

  std::cout << (res ? "First" : "Second") << std::endl;
  return 0;  
}
