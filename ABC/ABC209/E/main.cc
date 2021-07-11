#include <iostream>
#include <vector>
#include <string>
#include <queue>

int number(std::string s) {
  int res = 0;
  int base = 1;
  for (int i = 2; i >= 0; --i) {
    if (s[i] >= 'a' && s[i] <= 'z') res += (s[i] - 'a') * base;
    else res += (s[i] - 'A' + 26) * base;
    base *= 52;
  }
  return res;
}

int main() {
  const int SIZE = 52 * 52 * 52 + 1;
  int n;
  std::cin >> n;

  std::vector<std::string> s(n);
  for (int i = 0; i < n; ++i) std::cin >> s[i];

  std::vector<std::vector<int> > graph(SIZE);
  std::vector<std::vector<int> > graph_rev = graph;
  
  for (int i = 0; i < n; ++i) {
    int len = s[i].length();
    std::string pre = s[i].substr(0, 3);
    std::string suf = s[i].substr(len - 3, 3);
    int num_pre = number(pre);
    int num_suf = number(suf);
    graph[num_pre].push_back(num_suf);
    graph_rev[num_suf].push_back(num_pre);
  }

  std::queue<int> que;
  std::vector<int> res(SIZE, -1);
  for (int i = 0; i < SIZE; ++i) {
    if (graph[i].empty()) {
      res[i] = 1;
      que.push(i);
    }
  }

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int n_v : graph_rev[v]) {
      if (res[n_v] != -1) continue;
      if (res[v] == 1) { res[n_v] = 0; que.push(n_v); }
      else {
        bool all_lose = true;
        for (int n_n_v : graph[n_v]) if (res[n_n_v] != 0) all_lose = false;
        if (all_lose) { res[n_v] = 1; que.push(n_v); }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    int num = number(s[i].substr(s[i].length() - 3, 3));
    if (res[num] == 1) std::cout << "Takahashi" << std::endl;
    else if (res[num] == 0) std::cout << "Aoki" << std::endl;
    else std::cout << "Draw" << std::endl;
  }
  return 0;
}
