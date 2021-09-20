#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool connected(const int bit, const std::vector<std::vector<int> > &nx) {
  int s = 0;
  while (!(bit & (1 << s))) ++s;
  std::vector<bool> visited(16, false);
  visited[s] = true;
  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : nx[v]) {
      if (bit & (1 << nv) && !visited[nv]) {
        visited[nv] = true;
        que.push(nv);
      }
    }
  }
  for (int i = 0; i < 16; ++i) if (bit & (1 << i) && !visited[i]) return false;
  return true;
}

bool no_hole(const int bit, const std::vector<std::vector<int> > &nx, const std::vector<int> &ch) {
  for (int s : ch) {
    if (bit & (1 << s)) continue;
    bool ok = false;
    std::queue<int> que;
    std::vector<bool> visited(16, false);
    que.push(s);
    visited[s] = true;
    while (!que.empty() && !ok) {
      int v = que.front();
      que.pop();
      for (int nv : nx[v]) {
        if (!(bit & (1 << nv)) && !visited[nv]) {
          visited[nv] = true;
          que.push(nv);
          if (std::count(ch.begin(), ch.end(), nv) == 0) ok = true;
        }
      }
    }
    if (!ok) return false;
  }
  return true;
}

int main() {
  int village = 0;
  for (int i = 0; i < 16; ++i) {
    int a;
    std::cin >> a;
    village |= (a << i);
  }

  std::vector<std::vector<int> > nx(16);
  for (int i = 0; i < 16; ++i) {
    if (i % 4 > 0) nx[i].push_back(i - 1);
    if (i % 4 < 3) nx[i].push_back(i + 1);
    if (i / 4 > 0) nx[i].push_back(i - 4);
    if (i / 4 < 3) nx[i].push_back(i + 4);
  }

  std::vector<int> ch = {5, 6, 9, 10};
  
  int res = 0;
  for (int bit = village; bit < (1 << 16); bit = (bit + 1) | village) {
    if (!connected(bit, nx)) continue;
    if (no_hole(bit, nx, ch)) ++res;
  }

  std::cout << res << std::endl;
  return 0;  
}
