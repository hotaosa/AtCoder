#include <iostream>
#include <vector>
#include <algorithm>

int cnt(const std::vector<long long> &a, const std::vector<long long> &b, long long v) {
  long long res = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    res += std::lower_bound(b.begin(), b.end(), v / a[i] + 1) - b.begin();
  }
  return res;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  long long r = a.back() * b.back();
  long long l = 0LL;
  while (r - l > 1LL) {
    long long mid = (r + l) / 2LL;
    if (cnt(a, b, mid) < k) l = mid;
    else r = mid;
  }

  std::cout << r << std::endl;
  return 0;  
}
