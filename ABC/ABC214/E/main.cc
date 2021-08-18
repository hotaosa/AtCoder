#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

int main() {
  const int INF = 1 << 30;
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int> > vp(n);
    std::map<int, std::vector<int> > mv;
    for (int i = 0; i < n; ++i) {
      int l, r;
      std::cin >> l >> r;
      mv[l].push_back(r);
      vp[i] = std::make_pair(l, r);
    }
    std::sort(vp.begin(), vp.end());
    vp.push_back(std::make_pair(INF, INF));
    
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    int cur = vp[0].first;
    bool possible = true;
    while (cur <= 1000000000) {
      for (int p : mv[cur]) pq.push(p);
      int nx = pq.top();
      pq.pop();
      if (nx < cur) { possible = false; break; }
      if (!pq.empty()) {
        ++cur;
      } else {
        cur = std::lower_bound(vp.begin(), vp.end(), std::make_pair(cur + 1, 0))->first;
      }
    }
    if (!pq.empty()) possible = false;
    std::cout << (possible ? "Yes" : "No") << std::endl;
  }
  return 0;
}
