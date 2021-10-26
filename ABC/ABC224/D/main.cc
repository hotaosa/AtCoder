#include <iostream>
#include <string>
#include <map>
#include <queue>

int pos(std::string s) {
  for (int i = 0; i < (int)s.length(); ++i) if (s[i] == '8') return i;
  return -1;
}

int main() {
  std::vector<std::vector<int> > graph(9);
  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }
  std::string s(9, '8');
  for (int i = 0; i < 8; ++i) {
    int p;
    std::cin >> p;
    s[--p] = '0' + i;
  }

  std::map<std::string, int> ma;
  ma[s] = 0;
  std::queue<std::string> que;
  que.push(s);
  while (!que.empty()) {
    std::string cur = que.front();
    que.pop();
    int id = pos(cur);
    for (int nid : graph[id]) {
      std::string nx = cur;
      std::swap(nx[id], nx[nid]);
      if (ma.count(nx)) continue;
      ma[nx] = ma[cur] + 1;
      que.push(nx);
    }
  }

  if (ma.count("012345678")) std::cout << ma["012345678"] << std::endl;
  else std::cout << "-1" << std::endl;
  return 0;  
}
