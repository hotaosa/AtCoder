#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);  
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<long long, int> > vp;
  for (int i = 0; i < m; ++i) {
    int a;
    long long c;
    std::cin >> a >> c;
    vp.push_back(std::make_pair(c, a));
  }
  std::sort(vp.begin(), vp.end());

  long long res = 0LL;
  for (int i = 0; i < m; ++i) {
    if (n == 1) break;
    int n_new = gcd(n, vp[i].second);
    res += (n - n_new) * vp[i].first;
    n = n_new;
  }

  if (n == 1) std::cout << res << std::endl;
  else std::cout << "-1" << std::endl;
  return 0;
}
