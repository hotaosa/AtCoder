#include <iostream>
#include <vector>
#include <map>

int main() {
  int n, a;
  std::cin >> n >> a;
  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) { std::cin >> x[i]; x[i] -= a; }
  std::vector<std::map<int, long long> > vm(n + 1);
  ++vm[0][0];
  ++vm[0][x[0]];
  for (int i = 1; i < n; ++i) {
    for (auto ma : vm[i - 1]) {
      vm[i][ma.first] += vm[i - 1][ma.first];
      vm[i][ma.first + x[i]] += vm[i - 1][ma.first];
    }
  }
  std::cout << --vm[n - 1][0] << std::endl;
  return 0;  
}
