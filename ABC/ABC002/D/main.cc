#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> fr(n, std::vector<int>(n, false));
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    fr[a][b] = fr[b][a] = true;
  }
  int res = 1;
  for (int bit = 1; bit < (1 << n); ++bit) {
    int cnt = 0;
    std::vector<int> member;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        ++cnt;
        member.push_back(i);        
      }
    }
    if (cnt == 1) continue;
    bool possible = true;
    for (int i = 0; i < cnt - 1; ++i) {
      for (int j = i + 1; j < cnt; ++j) {
        if (!fr[member[i]][member[j]]) possible = false;
      }
    }
    if (possible) res = std::max(res, cnt);
  }
  std::cout << res << std::endl;
  return 0;  
}
