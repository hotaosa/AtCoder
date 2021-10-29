#include <iostream>
#include <vector>
#include <algorithm>

long long sum(std::vector<int> v, int l, int r) {
  long long ret = 0LL;
  for (int i = l; i <= r; ++i) ret += v[i];
  return ret;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  if (n > 1000) return 0;
  
  std::vector<std::pair<int, int> > lines(m);
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> l >> r;
    lines[i].first = --r;
    lines[i].second = --l;
  }
  std::sort(lines.begin(), lines.end());  

  long long sub = 0LL;
  std::vector<int> cnt_l(n, 0), cnt_r(n, 0);
  for (int i = 0; i < m; ++i) {
    int r = lines[i].first, l = lines[i].second;
    sub += cnt_l[l] + cnt_l[r] + cnt_r[l] + cnt_r[r];
    if (l > 0) sub += sum(cnt_r, 0, l - 1);
    sub += sum(cnt_l, l + 1, r - 1);
    ++cnt_l[l];
    ++cnt_r[r];    
  }
  
  long long res = (long long)m * (m - 1) / 2LL - sub;
  std::cout << res << std::endl;  
  return 0;
}
