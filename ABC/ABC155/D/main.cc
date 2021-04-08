#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  const long long INF = 1LL << 60;
  int n;
  long long k;
  std::cin >> n >> k;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  long long left = -INF, right = INF;
  while (right - left > 1) {
    long long mid = (left + right) / 2LL;
    long long s = 0LL, t = 0LL;
    for (int i = 0; i < n; ++i) {
      if (a[i] > 0) {
        int l2 = -1, r2 = n;
        while (r2 - l2 > 1) {
          int m = (l2 + r2) / 2;
          if (a[i] * a[m] <= mid) l2 = m;
          else r2 = m;
        }
        s += r2;
      } else if (a[i] < 0) {
        int l2 = -1, r2 = n;
        while (r2 - l2 > 1) {
          int m = (l2 + r2) / 2;
          if (a[i] * a[m] <= mid) r2 = m;
          else l2 = m;
        }
        s += n - r2;
      } else if (mid >= 0) s += n;
      if (a[i] * a[i] <= mid) ++t;
    }
    long long num = (s - t) / 2;
    if (num >= k) right = mid;
    else left = mid;
  }
  std::cout << right << std::endl;
  return 0;
}
