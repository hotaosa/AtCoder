#include <iostream>
#include <string>
#include <set>

void dfs(std::string cur, int flag, int o, int c, int len, std::set<std::string> &res) {
  if (flag == 0) {
    cur += '(';
    ++o;
  } else {
    cur += ')';
    ++c;
  }
  if (o + c == len && o == c) {
    res.insert(cur);
    return;
  }
  if (o < len / 2) dfs(cur, 0, o, c, len, res);
  if (c < o) dfs(cur, 1, o, c, len, res);
  return;
}

int main() {
  int n;
  std::cin >> n;
  if (n & 1) return 0;

  std::set<std::string> res;
  dfs("", 0, 0, 0, n, res);

  for (auto s : res) std::cout << s << std::endl;
  return 0;
}
