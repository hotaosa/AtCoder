#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;

  std::vector<std::pair<char, int>> vp;
  for (int i = 0; i < n; ++i) vp.push_back(std::make_pair(s[i], i));
  std::sort(vp.begin(), vp.end());

  std::vector<int> res(k, -1);
  int cnt = 0;
  for (int i = 0; i < n && cnt < k; ++i) {
    int index = std::max(0, k - (n - vp[i].second));
    while (index < k && res[index] != -1) {
      if (vp[i].second < res[index]) break;
      ++index;
    }
    if (index < k && res[index] == -1) {
      res[index] = vp[i].second;
      ++cnt;
    }
  }

  for (int i : res) std::cout << s[i];
  std::cout << std::endl;
  return 0;
}
