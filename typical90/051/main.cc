#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, k;
  long long p;
  std::cin >> n >> k >> p;

  int size1 = n / 2, size2 = n - n / 2;  
  std::vector<long long> a1(size1), a2(size2);
  for (int i = 0; i < size1; ++i) std::cin >> a1[i];
  for (int i = 0; i < size2; ++i) std::cin >> a2[i];
  
  std::vector<std::vector<long long> > halfSum1(size1 + 1), halfSum2(size2 + 1);

  for (int bit = 1; bit < (1 << size1); ++bit) {
    long long sum = 0LL;
    int cnt = 0;
    for (int i = 0; i < size1; ++i) {
      if (bit & (1 << i)) {
        sum += a1[i];
        ++cnt;
      }
    }
    halfSum1[cnt].push_back(sum);
  }
  for (int i = 0; i <= size1; ++i) std::sort(halfSum1[i].begin(), halfSum1[i].end());

  for (int bit = 1; bit < (1 << size2); ++bit) {
    long long sum = 0LL;
    int cnt = 0;
    for (int i = 0; i < size2; ++i) {
      if (bit & (1 << i)) {
        sum += a2[i];
        ++cnt;
      }
    }
    halfSum2[cnt].push_back(sum);
  }
  for (int i = 0; i <= size2; ++i) std::sort(halfSum2[i].begin(), halfSum2[i].end());

  long long res = 0LL;
  if (size1 >= k) {
    res += std::upper_bound(halfSum1[k].begin(), halfSum1[k].end(), p) - halfSum1[k].begin();
  }
  if (size2 >= k) {
    res += std::upper_bound(halfSum2[k].begin(), halfSum2[k].end(), p) - halfSum2[k].begin();
  }
  
  for (int i = 1; i <= size1 && i < k; ++i) {
    if (k - i > size2) continue;
    for (long long half1 : halfSum1[i]) {
      if (half1 > p) continue;
      long long half2 = p - half1;
      res += std::upper_bound(halfSum2[k - i].begin(), halfSum2[k - i].end(), half2) - halfSum2[k - i].begin();
    }
  }

  std::cout << res << std::endl;
  return 0;
}
