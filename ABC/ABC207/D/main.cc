#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using vp = std::vector<std::pair<double, double> >;

int main() {
  const double TOL = 1e-01;
  
  int n;
  std::cin >> n;
  vp s, t;
  for (int i = 0; i < n; ++i) {
    double a, b;
    std::cin >> a >> b;
    s.push_back(std::make_pair(a, b));
  }
  for (int i = 0; i < n; ++i) {
    double c, d;
    std::cin >> c >> d;
    t.push_back(std::make_pair(c, d));
  }

  std::sort(t.begin(), t.end());
  vp t_dis(n);
  t_dis[0] = std::make_pair(0.0, 0.0);
  for (int i = 1; i < n; ++i) {
    t_dis[i].first = t[i].first - t[0].first;
    t_dis[i].second = t[i].second - t[0].second;
  }

  auto rot = [&](vp s, double dr) -> vp {
    vp res;
    for (int i = 0; i < n; ++i) {      
      double x = s[i].first;
      double y = s[i].second;
      res.push_back(std::make_pair(x * std::cos(dr) - y * std::sin(dr), x * std::sin(dr) + y * std::cos(dr)));
    }
    return res;
  };
  
  double dr = 2 * M_PI / 1000;
  for (int i = 0; i < 2000; ++i) {
    vp ss = rot(s, dr * i);
    std::sort(ss.begin(), ss.end());
    vp ss_dis(n);
    ss_dis[0] = std::make_pair(0.0, 0.0);
    bool is_same = true;
    for (int i = 1; i < n && is_same; ++i) {
      ss_dis[i].first = ss[i].first - ss[0].first;
      ss_dis[i].second = ss[i].second - ss[0].second;
      if (std::abs(ss_dis[i].first - t_dis[i].first) > TOL) is_same = false;
      if (std::abs(ss_dis[i].second - t_dis[i].second) > TOL) is_same = false;
    }
    if (is_same) { std::cout << "Yes" << std::endl; return 0; }
  }

  std::cout << "No" << std::endl;
  return 0;
}
