#include <iostream>
#include <vector>

struct Train{
  int prev, next;
  Train() : prev(-1), next(-1) { }
};

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<Train> tr(n, Train());
  while (q--) {
    int qu;
    std::cin >> qu;
    if (qu == 1) {
      int x, y;
      std::cin >> x >> y;
      --x;
      --y;
      tr[x].next = y;
      tr[y].prev = x;      
    } else if (qu == 2) {
      int x, y;
      std::cin >> x >> y;
      --x;
      --y;
      tr[x].next = -1;
      tr[y].prev = -1;
    } else {
      int x;
      std::cin >> x;
      --x;
      std::vector<int> res;
      while (tr[x].prev != -1) x = tr[x].prev;
      do {
        res.push_back(x);
        x = tr[x].next;
      } while (x != -1);
      std::cout << res.size() << " ";
      for (int r : res) std::cout << r + 1 << " ";
      std::cout << std::endl;
    }
  }
  return 0;
}
