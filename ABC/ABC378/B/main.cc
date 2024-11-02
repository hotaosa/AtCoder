#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> q(n), r(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> q[i] >> r[i];
  }

  int qn;
  std::cin >> qn;
  while (qn--) {
    int t, d;
    std::cin >> t >> d;
    --t;

    int add = (r[t] - d % q[t] + q[t]) % q[t];
    std::cout << d + add << "\n";
  }

  return 0;
}