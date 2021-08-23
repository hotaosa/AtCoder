#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void dfs(const std::vector<int> &chs, int pos, std::string cur,
         std::vector<bool> used, std::vector<std::string> &res, int len) {
  used[pos] = true;
  cur += 'a' + chs[pos];
  if ((int)cur.length() == len) {
    res.push_back(cur);
    return;
  }

  for (int i = 0; i < len; ++i) {
    if (!used[i]) dfs(chs, i, cur, used, res, len);
  }
}

int main() {
  std::string s;
  int k;
  std::cin >> s >> k;
  int n = (int)s.length();

  std::vector<int> chs(n);
  for (int i = 0; i < n; ++i) chs[i] = s[i] - 'a';
  std::sort(chs.begin(), chs.end());

  std::vector<std::string> res;
  std::vector<bool> used(n, false);
  std::string cur = "";
  for (int i = 0; i < n; ++i) dfs(chs, i, cur, used, res, n);

  std::sort(res.begin(), res.end());
  res.erase(std::unique(res.begin(), res.end()), res.end());
  std::cout << res[k - 1] << std::endl;

  return 0;  
}
