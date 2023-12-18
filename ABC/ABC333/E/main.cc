#include <iostream>
#include <stack>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> t(n), x(n), res(n, -1);
  std::vector<std::stack<int> > discovered_idx(n), used_idx(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> t[i] >> x[i];
    if (t[i] == 1) {
      res[i] = 0;
      discovered_idx[--x[i]].push(i);
    } else {
      used_idx[--x[i]].push(i);
    }
  }

  for (int i = 0; i < n; ++i) {
    while (!used_idx[i].empty()) {
      int idx = used_idx[i].top();
      used_idx[i].pop();
      while (!discovered_idx[i].empty() && discovered_idx[i].top() > idx) {
        discovered_idx[i].pop();
      }
      if (discovered_idx[i].empty()) {
        std::cout << "-1\n";
        return 0;
      }
      res[discovered_idx[i].top()] = 1;
      discovered_idx[i].pop();
    }
  }

  int k = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i] == 2) {
      --cur;
    } else if (res[i] == 1) {
      ++cur;
    }
    k = std::max(k, cur);
  }

  std::cout << k << std::endl;
  for (auto r : res) if (r != -1) std::cout << r << " ";
  std::cout << std::endl;

  return 0;
}