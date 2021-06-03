#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  long long k;
  std::cin >> n >> k;
  std::vector<std::pair<long long, long long> > vp;
  for (int i = 0; i < n; ++i) {
    long long a, b;
    std::cin >> a >> b;
    vp.push_back(std::make_pair(a, b));
  }
  std::sort(vp.begin(), vp.end());

  long long cur = 0;
  int index = 0;
  while (k > 0) {
    cur += k;
    k = 0;
    while (index < n && vp[index].first <= cur) k += vp[index++].second;
  }

  std::cout << cur << std::endl;
  return 0;
}
