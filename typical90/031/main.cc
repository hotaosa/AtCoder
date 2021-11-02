#include <iostream>
#include <vector>
#include <set>

int mex(std::set<int> se) {
  int ret = 0;
  while (se.count(ret)) ++ret;
  return ret;
}

int grundy(int w, int b, std::vector<std::vector<int> > &mem) {
  if (mem[w][b] != -1) return mem[w][b];
  std::set<int> se;
  if (w >= 1) se.insert(grundy(w - 1, b + w, mem));
  if (b >= 2) for (int k = 1; k <= b / 2; ++k) se.insert(grundy(w, b - k, mem));
  return mem[w][b] = mex(se);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> w(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> w[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];

  std::vector<std::vector<int> > mem(51, std::vector<int>(2551, -1));
  mem[0][0] = 0;
  mem[0][1] = 0;

  int xsum = 0;
  for (int i = 0; i < n; ++i) xsum ^= grundy(w[i], b[i], mem);
  std::cout << (xsum ? "First" : "Second") << std::endl;
  return 0;
}
