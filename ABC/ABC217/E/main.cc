#include <iostream>
#include <queue>

int main() {
  int q;
  std::cin >> q;
  std::queue<int> que;
  std::priority_queue<int, std::vector<int>, std::greater<int> > pque;
  while (q--) {
    int qq;
    std::cin >> qq;
    if (qq == 1) {
      int x;
      std::cin >> x;
      que.push(x);
    } else if (qq == 2) {
      if (!pque.empty()) {
        std::cout << pque.top() << std::endl;
        pque.pop();
      } else {
        std::cout << que.front() << std::endl;
        que.pop();
      }
    } else {
      while (!que.empty()) {
        pque.push(que.front());
        que.pop();
      }
    }
  }
  return 0;
}
