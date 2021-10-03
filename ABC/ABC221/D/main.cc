#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > event;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    event.push_back(std::make_pair(a, 1));
    event.push_back(std::make_pair(a + b, -1));
  }
  std::sort(event.begin(), event.end());

  std::vector<int> res(n + 1, 0);
  int cur = 1;
  for (int i = 1; i < n * 2; ++i) {
    res[cur] += event[i].first - event[i - 1].first;
    cur += event[i].second;
  }

  for (int i = 1; i <= n; ++i) std::cout << res[i] << " ";
  std::cout << std::endl;
  return 0;  
}
