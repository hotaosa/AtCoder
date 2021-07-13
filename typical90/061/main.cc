#include <iostream>
#include <queue>

int main() {
  int q;
  std::cin >> q;
  std::deque<int> dq;
  for (int i = 0; i < q; ++i) {
    int t, x;
    std::cin >> t >> x;
    if (t == 1) dq.push_front(x);
    else if (t == 2) dq.push_back(x);
    else std::cout << dq[--x] << std::endl;
  }
  return 0;
}
