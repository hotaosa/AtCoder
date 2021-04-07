#include <bits/stdc++.h>

int main() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  if (k <= 1) { std::cout << s << std::endl; return 0; }

  auto diff = [&](std::vector<int> v1, std::vector<int> v2) -> int {
    int cnt = 0;
    for (int i = 0; i < (int)v1.size(); ++i) cnt += std::max(0, v1[i] - v2[i]);
    return cnt;
  };

  std::vector<int> a(26, 0), b(26, 0);
  for (int i = 0; i < n; ++i) {
    ++a[s[i] - 'a'];
    ++b[s[i] - 'a'];
  }

  std::string res = "";
  int d = 0;
  for (int i = 0; i < n; ++i) {
    --a[s[i] - 'a'];
    if (d == k) {
      res += s[i];
      continue;
    }
    for (int j = 0; j < 26; ++j) {
      if (b[j] == 0) continue;
      if (s[i] - 'a' == j) {
        --b[j];
        res += s[i];
        break;
      }
      --b[j];
      if (d + 1 + diff(a, b) <= k) {
        ++d;
        res += (char)(j + 'a');
        break;
      }
      ++b[j];        
    }
  }
  std::cout << res << std::endl;
  return 0;  
}
