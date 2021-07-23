#include <iostream>
#include <map>

int func(std::map<long long, int> &ma, long long n) {
  if (ma.count(n)) return ma[n];
  for (int i = 1; i < 5; ++i) {
    for (long long r = i; r <= 3 * i; ++r) {
      if ((n - r) % 10) continue;
      if (func(ma, (n - r) / 10) <= i) return ma[n] = i;
    }
  }
  return ma[n] = 5;
}

int main() {
  std::map<long long, int> ma;
  ma[0] = 0;
  
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    long long n;
    std::cin >> n;
    std::cout << func(ma, n) << std::endl;
  }
  return 0;
}
