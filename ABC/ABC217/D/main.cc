#include <iostream>
#include <set>

int main() {
  int l, q;
  std::cin >> l >> q;

  std::set<int> se;
  se.insert(0);
  se.insert(l);
  
  while (q--) {
    int c, x;
    std::cin >> c >> x;

    if (c == 1) {
      se.insert(x);
    } else {
      auto p = se.lower_bound(x);
      auto pm = p;
      --pm;
      std::cout << *p - *pm << std::endl;
    }
  }
  return 0;
}
