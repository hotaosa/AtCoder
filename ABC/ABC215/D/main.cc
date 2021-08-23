#include <iostream>
#include <vector>
#include <set>

void insert_prime_factor(std::set<int> &pfs, int a) {
  for (int i = 2; i * i <= a; ++i) {
    if (a % i == 0) {
      pfs.insert(i);
      while (a % i == 0) a /= i;
    }
  }
  if (a != 1) pfs.insert(a);
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::set<int> pfs;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    insert_prime_factor(pfs, a);
  }

  std::vector<bool> rem(m + 1, true);
  for (int num : pfs) {
    for (int i = num; i <= m; i += num) rem[i] = false;
  }

  std::vector<int> res;
  for (int i = 1; i <= m; ++i) if (rem[i]) res.push_back(i);

  std::cout << res.size() << std::endl;
  for (int r : res) std::cout << r << std::endl;
  return 0;  
}
