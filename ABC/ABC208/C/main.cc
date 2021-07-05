#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  std::vector<std::pair<int, int> > vp;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    vp.push_back(std::make_pair(a, i));
  }

  std::sort(vp.begin(), vp.end());
  std::vector<long long> res(n, k / n);
  for (int i = 0; i < k % (long long)n; ++i) ++res[vp[i].second];

  for (long long r : res) std::cout << r << std::endl;
  return 0;  
}
