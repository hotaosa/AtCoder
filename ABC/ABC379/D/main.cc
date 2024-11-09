#include <iostream>
#include <queue>

void ReadQuery(int* type, long long* wait, long long* height) {
  std::cin >> *type;
  if (*type == 2) {
    std::cin >> *wait;
  } else if (*type == 3) {
    std::cin >> *height;
  }
}

int main() {
  int q;
  std::cin >> q;

  int type;
  long long wait, height, offset = 0;

  std::priority_queue<long long> pque;
  while (q--) {
    ReadQuery(&type, &wait, &height);
    if (type == 1) {
      pque.emplace(-offset);
    } else if (type == 2) {
      offset += wait;
    } else {
      int count = 0;
      while (!std::empty(pque) && pque.top() >= height - offset) {
        ++count;
        pque.pop();
      }
      std::cout << count << "\n";
    }
  }

  return 0;
}