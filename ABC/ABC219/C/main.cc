#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  std::string x;
  int n;
  std::cin >> x >> n;
  std::vector<std::string> vs(n);
  for (int i = 0; i < n; ++i) std::cin >> vs[i];

  std::vector<int> order(26);
  for (int i = 0; i < 26; ++i) order[x[i] - 'a'] = i;

  auto comp = [&](const std::string &lh, const std::string &rh) -> bool {
    for (int i = 0; i < (int)std::min(lh.length(), rh.length()); ++i) {
      if (lh[i] == rh[i]) continue;
      return order[lh[i] - 'a'] < order[rh[i] - 'a'];
    }
    return lh.length() < rh.length();
  };

  std::sort(vs.begin(), vs.end(), comp);
  for (std::string res : vs) std::cout << res << std::endl;
  return 0;
}
