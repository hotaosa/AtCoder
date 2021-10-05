#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());

  std::vector<std::pair<int, int> > vp(m);
  for (int i = 0; i < m; ++i) std::cin >> vp[i].second >> vp[i].first;
  std::sort(vp.begin(), vp.end(), std::greater<std::pair<int, int> >());

  for (int i = 0, cur = 0; i < m; ++i) {
    int val = vp[i].first;
    int num = vp[i].second;
    while (num--) {
      if (cur < n && a[cur] < val) {
        a[cur++] = val;
      } else break;
    }
  }

  long long res = 0LL;
  for (int v : a) res += v;
  std::cout << res << std::endl;
  return 0;  
}
