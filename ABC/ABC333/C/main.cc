#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  constexpr int SIZE = 13;
  std::vector<long long> repunit(SIZE, 1LL);
  for (int i = 1; i < SIZE; ++i) {
    repunit[i] = repunit[i - 1] * 10 + 1;
  }

  std::vector<long long> sum_repunit;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = i; j < SIZE; ++j) {
      for (int k = j; k < SIZE; ++k) {
        sum_repunit.emplace_back(repunit[i] + repunit[j] + repunit[k]);
      }
    }
  }

  std::sort(sum_repunit.begin(), sum_repunit.end());
  std::cout << sum_repunit[--n] << std::endl;
  return 0;
}