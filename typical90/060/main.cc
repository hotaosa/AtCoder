#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<int> len_left(n, 0), len_right(n, 0);

  std::vector<int> b;
  for (int i = 0; i < n; ++i) {
    int cnt = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    if (cnt == (int)b.size()) b.push_back(a[i]);
    else b[cnt] = a[i];
    len_left[i] = cnt + 1;
  }

  b.clear();
  for (int i = n - 1; i >= 0; --i) {
    int cnt = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    if (cnt == (int)b.size()) b.push_back(a[i]);
    else b[cnt] = a[i];
    len_right[i] = cnt + 1;
  }


  int res = 0;
  for (int i = 0; i < n; ++i) {
    res = std::max(res, len_left[i] + len_right[i] - 1);
  }
  std::cout << res << std::endl;
  
  return 0;
}
