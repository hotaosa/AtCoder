#include <iostream>
#include <vector>

int main() {
  int n, l, k;
  std::cin >> n >> l >> k;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  auto judge = [&](int m) -> bool {
    int cur = 0, cnt = 1;
    for (int i = 0; i < n; ++i) {
      if (a[i] - cur >= m) {
        ++cnt;
        cur = a[i];
      }
    }
    if (cnt > k + 1) return true;
    else if (cnt > k && l - cur >= m) return true;
    return false;
  };

  int ok = 0, ng = l + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (judge(mid)) ok = mid;
    else ng = mid;
  }

  std::cout << ok << std::endl;
  return 0;  
}
