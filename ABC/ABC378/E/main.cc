#include <iostream>
//
#include <atcoder/fenwicktree>

int main() {
  int n, m;
  std::cin >> n >> m;

  atcoder::fenwick_tree<int> ft(m);
  long long res = 0, sum = 0, ssum = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    std::cin >> a;
    sum = (sum + a) % m;
    res += sum * i - ssum + static_cast<long long>(m) * ft.sum(sum + 1, m);
    ssum += sum;
    ft.add(sum, 1);
  }

  std::cout << res << "\n";
  return 0;
}