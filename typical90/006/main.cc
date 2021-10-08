#include <iostream>
#include <vector>
#include <string>

int main() {
  constexpr int INF = 1 << 30;
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i) vec[i] = s[i] - 'a';

  std::vector<std::vector<int> > nx(n + 1, std::vector<int>(26, INF));
  
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      nx[i][j] = nx[i + 1][j];
    }
    nx[i][vec[i]] = i;
  }

  std::string res = "";
  for (int len = 0, cur = 0; len < k; ++len) {
    for (int i = 0; i < 26; ++i) {
      if (n - nx[cur][i] >= k - len) {
        res += 'a' + i;
        cur = nx[cur][i] + 1;
        break;
      }
    }
  }
  
  std::cout << res << std::endl;
  
  return 0;
}
