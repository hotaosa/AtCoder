#include <iostream>
#include <vector>

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  std::vector<long long> a(n);
  long long ma = 0LL, sum = 0LL;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ma = std::max(ma, a[i]);
    sum += a[i];
  }

  auto cntup = [&](long long a, long long b) -> long long {
    return (a + b) * (a - b + 1LL) / 2LL;
  };

  auto judge = [&](long long val) -> bool {
    long long cnt = 0LL;
    for (int i = 0; i < n; ++i) if (a[i] > val) cnt += a[i] - val;
    return cnt >= k;
  };

  if (k >= sum) {
    long long res = 0LL;
    for (int i = 0; i < n; ++i) res += cntup(a[i], 1LL);
    std::cout << res << std::endl;
    return 0;
  }
  
  long long l = 0, r = ma + 1LL;
  while (r - l > 1LL) {
    long long m = (l + r) / 2LL;
    if (judge(m)) l = m;
    else r = m;    
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < r) continue;
    res += cntup(a[i], r + 1LL);
    k -= a[i] - r;
  }
  res += r * k;
  std::cout << res << std::endl;
  return 0;  
}
