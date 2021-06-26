#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<long long> sum(n), xsum(n);
  sum[0] = xsum[0] = a[0];
  for (int i = 1; i < n; ++i) {
    sum[i] = sum[i - 1] + a[i];
    xsum[i] = xsum[i - 1] ^ a[i];
  }

  auto judge = [&](int i, int v) -> bool {
    if (i == 0) return sum[v] == xsum[v];
    return (sum[v] - sum[i - 1]) == (xsum[v] ^ xsum[i - 1]);
  };

  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (judge(i, mid)) l = mid;
      else r = mid;
    }
    res += l - i + 1;
  }

  std::cout << res << std::endl;
  return 0;  
}
