#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  std::string s;
  int k;
  std::cin >> s >> k;

  int n = (int)s.length();  
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) v[i] = s[i] - 'a';
  std::sort(v.begin(), v.end());

  std::vector<int> res;
  int cnt = 0;
  do {
    ++cnt;
    if (cnt == k) res = v;
  } while (std::next_permutation(v.begin(), v.end()));

  for (int d : res) std::cout << (char)('a' + d);
  std::cout << std::endl;
  return 0;
}
