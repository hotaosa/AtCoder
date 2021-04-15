#include <bits/stdc++.h>

int main() {
  std::vector<std::string> s(3);
  for (int i = 0; i < 3; ++i) std::cin >> s[i];

  std::set<char> se;
  for (int i = 0; i < 3; ++i) {
    for (char c : s[i]) se.insert(c);
  }

  bool possible = false;
  int kind = (int)se.size();
  std::vector<long long> n(3, 0);
  if (kind <= 10) {
    std::vector<int> num(10);
    for (int i = 0; i < 10; ++i) num[i] = i;

    do {
      std::map<char, int> ma;
      int i = 0;
      for (char c : se) {
        ma[c] = num[i++];
      }
      n.assign(3, 0);
      if (ma[s[0][0]] == 0 || ma[s[1][0]] == 0 || ma[s[2][0]] == 0) continue;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < (int)s[i].length(); ++j) {
          n[i] = n[i] * 10 + ma[s[i][j]];
        }
      }

      if (n[0] + n[1] == n[2]) { possible = true; break; }
    } while (std::next_permutation(num.begin(), num.end()));
  }

  if (possible) for (auto res : n) std::cout << res << std::endl;
  else std::cout << "UNSOLVABLE" << std::endl;
  return 0;
}
