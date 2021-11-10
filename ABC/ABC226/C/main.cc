#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > graph(n);
  std::vector<long long> t(n);
  
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> t[i] >> k;
    for (int j = 0; j < k; ++j) {
      int a;
      std::cin >> a;
      graph[i].push_back(--a);
    }
  }

  long long res = 0LL;
  std::vector<bool> done(n, false);
  std::queue<int> que;
  que.push(n - 1);
  done[n - 1] = true;
  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    res += t[cur];
    for (int nx : graph[cur]) if (!done[nx]) { que.push(nx); done[nx] = true; }
  }

  std::cout << res << std::endl;
  return 0;
}
