#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void chmax(int &a, int b) { a = std::max(a, b); }

struct DelayMap {
  std::map<int, int> mr, mc, dr, dc;
  int get(int r, int c) { return std::max(mr[r], mc[c]); }
  void stock(int r, int c, int val) {
    chmax(dr[r], val);
    chmax(dc[c], val);
  }
  void update() {
    for (auto m : dr) mr[m.first] = m.second;
    dr.clear();
    for (auto m : dc) mc[m.first] = m.second;
    dc.clear();    
  }
};

int main() {
  int h, w, n;
  std::cin >> h >> w >> n;
  std::vector<int> r(n), c(n);
  std::vector<std::pair<int, int> > vp(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> r[i] >> c[i] >> vp[i].first;
    vp[i].second = i;
  }
  std::sort(vp.begin(), vp.end(), std::greater<>());
  
  std::vector<int> res(n);
  DelayMap dm;
  int pre = vp[0].first;
  for (int i = 0; i < n; ++i) {
    int val = vp[i].first;
    int id = vp[i].second;
    if (val < pre) dm.update();
    res[id] = dm.get(r[id], c[id]);
    dm.stock(r[id], c[id], res[id] + 1);
    pre = val;
  }

  for (int r : res) std::cout << r << std::endl;
  return 0;
}
