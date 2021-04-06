#include <bits/stdc++.h>

int main() {
  const long long INF = 1LL << 60;
  
  long long n, h, a, b, c, d, e;
  std::cin >> n >> h >> a >> b >> c >> d >> e;

  if (h - e * n > 0) { std::cout << "0" << std::endl; return 0; }

  long long res = INF;
  for (long long good = 0LL; good <= n; ++good) {
    long long lack = e * n - h + 1 - good * (b + e);
    long long bad = 0LL;
    if (lack >= 0) bad = (lack + d + e - 1LL) / (d + e);
    res = std::min(res, good * a + bad * c);   
  }

  std::cout << res << std::endl;
  return 0;  
}
