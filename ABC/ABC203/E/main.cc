#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int> > vp(m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    vp[i] = {x, y};
  }
  sort(vp.begin(), vp.end());
  set<int> se, add, remove;
  se.insert(n);

  auto update = [&]() -> void {
    for (auto v : remove) se.erase(v);
    for (auto v : add) se.insert(v);
    add.clear();
    remove.clear();
  };
  
  for (int i = 0; i < m; ++i) {
    if (i > 0 && vp[i].first > vp[i - 1].first) update();
    remove.insert(vp[i].second);
    if (se.count(vp[i].second - 1) || se.count(vp[i].second + 1)) add.insert(vp[i].second);        
  }
  update();
  cout << se.size() << endl;
  return 0;
}