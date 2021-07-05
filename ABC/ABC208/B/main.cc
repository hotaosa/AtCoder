#include <iostream>
#include <vector>

int main() {
  long long p;
  std::cin >> p;

  std::vector<std::pair<long long, int> > vp;
  long long cur = 1LL;
  for (int i = 1; i <= 10; ++i) {
    cur *= i;
    vp.push_back(std::make_pair(cur, 100));
  }

  int res = 0;
  for (int i = 9; i >= 0; --i) {
    while (p >= vp[i].first && vp[i].second > 0) {
      ++res;
      p -= vp[i].first;
      --vp[i].second;
    }
  }

  std::cout << res << std::endl;
  return 0;  
}
