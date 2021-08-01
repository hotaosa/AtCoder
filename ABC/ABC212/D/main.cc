#include <iostream>
#include <queue>

int main() {
  int q;
  std::cin >> q;
  
  std::priority_queue<long long, std::vector<long long>, std::greater<long long> > que;
  long long base = 0LL;
  
  while (q--) {
    int qq;
    std::cin >> qq;
    if (qq == 3) {
      std::cout << que.top() + base << std::endl;
      que.pop();
    } else {
      long long x;
      std::cin >> x;
      if (qq == 2) base += x;
      else que.push(x - base);
    }
  }

  return 0;
}
