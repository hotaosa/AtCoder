#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int n, m;
  std::cin >> n >> m;
  std::vector<int> w(n);
  int w_max = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> w[i];
    w_max = std::max(w_max, w[i]);
  }
  std::sort(w.begin(), w.end());

  int v_min = 1 << 30;
  std::vector<std::pair<int, int> > vp;
  for (int i = 0; i < m; ++i) {
    int l, v;
    std::cin >> l >> v;
    v_min = std::min(v_min, v);
    vp.push_back(std::make_pair(v, l));
  }
  
  if (w_max > v_min) { std::cout << -1 << std::endl; return 0; }
  
  std::sort(vp.begin(), vp.end());
  std::vector<int> l(m), v(m);
  for (int i = 0; i < m; ++i) {
    l[i] = vp[i].second;
    v[i] = vp[i].first;
  }
  for (int i = 1; i < m; ++i) l[i] = std::max(l[i], l[i - 1]);

  int res = 1 << 30;
  do {
    std::vector<int> dist(n, 0);
    for (int i = 0; i < n - 1; ++i) {
      int w_sum = w[i];
      for (int j = i + 1; j < n; ++j) {
        w_sum += w[j];
        int over_index = std::lower_bound(v.begin(), v.end(), w_sum) - v.begin() - 1;
        if (over_index >= 0) dist[j] = std::max(dist[j], dist[i] + l[over_index]);
        else dist[j] = std::max(dist[j], dist[i]);
      }
    }  
    res = std::min(res, dist[n - 1]);
  } while (std::next_permutation(w.begin(), w.end()));

  std::cout << res << std::endl;
  return 0;
}
