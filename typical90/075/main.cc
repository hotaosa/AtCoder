#include <iostream>
#include <map>

int main() {
  long long n;
  std::cin >> n;

  std::map<long long, int> ma;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ++ma[i];
      n /= i;
    }
  }
  if (n > 1) ++ma[n];

  int tot = 0;
  for (auto m : ma) tot += m.second;
  int res = 0, cnt = 1;
  while (cnt < tot) { ++res; cnt *= 2; }
  std::cout << res << std::endl;
  
  return 0; 
}
