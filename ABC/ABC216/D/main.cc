#include <iostream>
#include <vector>
#include <set>
#include <queue>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::queue<int> > vq(m);
  for (int i = 0; i < m; ++i) {
    int k;
    std::cin >> k;
    for (int j = 0; j < k; ++j) {
      int a;
      std::cin >> a;
      vq[i].push(a);
    }
  }

  std::set<int> se1, se2;
  std::vector<std::vector<int> > tp(n + 1);

  auto se_push = [&](int num) -> void {
    if (!se1.count(num)) se1.insert(num);
    else {
      se1.erase(num);
      se2.insert(num);
    }
  };

  auto q_pop = [&](int id) -> void {
    vq[id].pop();
    if (vq[id].empty()) return;
    se_push(vq[id].front());
    tp[vq[id].front()].push_back(id);
  };

  for (int i = 0; i < m; ++i) {
    int num = vq[i].front();
    tp[num].push_back(i);
    se_push(num);
  }
  
  for (int i = 0; i < n; ++i) {
    if (se2.empty()) { std::cout << "No" << std::endl; return 0; }
    int num = *se2.begin();
    se2.erase(num);
    for (int id : tp[num]) q_pop(id);
  }

  std::cout << "Yes" << std::endl;
  return 0;  
}
