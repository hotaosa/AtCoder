#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


int main() {
  long long k;
  std::cin >> k;

  std::set<std::vector<long long> > res;
  for (long long n = 1; n * n <= k; ++n) {
    if (k % n == 0) {
      long long kk = k / n;
      for (long long nn = 1; nn * nn <= kk; ++nn) {
        if (kk % nn == 0) {
          std::vector<long long> v;
          v.push_back(n);
          v.push_back(nn);
          v.push_back(kk / nn);
          std::sort(v.begin(), v.end());
          res.insert(v);
        }
      }
    }
  }

  std::cout << res.size() << std::endl;
  return 0;
}
