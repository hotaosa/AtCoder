#include <iostream>
#include <vector>

int main() {
  constexpr long long INF = 1LL << 60;
  int n, x;
  std::cin >> n >> x;

  std::vector<long long> a(n), p(n), b(n), q(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> p[i] >> b[i] >> q[i];
    if (a[i] * q[i] < b[i] * p[i]) {
      std::swap(a[i], b[i]);
      std::swap(p[i], q[i]);
    }
  }

  auto Judge = [&](long long m) -> bool {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      long long cur = INF;
      for (long long cb = 0; cb <= std::min((m + b[i] - 1) / b[i], a[i]);
           ++cb) {
        long long ca = (m - cb * b[i] + a[i] - 1) / a[i];
        cur = std::min(cur, p[i] * ca + q[i] * cb);
      }
      sum += cur;
      if (sum > x) return false;
    }
    return true;
  };

  long long l = 0, r = x * 100 + 1;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    (Judge(m) ? l : r) = m;
  }

  std::cout << l << "\n";
  return 0;
}