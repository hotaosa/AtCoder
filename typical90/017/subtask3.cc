#include <iostream>
#include <vector>
#include <algorithm>

struct BIT {
  int n;
  std::vector<long long> dat;
  BIT(int n_) : n(n_), dat(n_ + 1, 0LL) { }
  void add(int i, long long x) { for (++i; i <= n; i += (i & -i)) dat[i] += x; }
  long long sum(int i) {
    long long ret = 0LL;
    for (++i; i > 0; i -= (i & -i)) ret += dat[i];
    return ret;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int> > lines(m);
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> l >> r;
    lines[i].first = --r;
    lines[i].second = --l;
  }
  std::sort(lines.begin(), lines.end());

  long long res = (long long)m * (m - 1) / 2LL;
  std::vector<int> cnt_l(n, 0), cnt_r(n, 0);
  BIT bit_l(n), bit_r(n);
  for (int i = 0; i < m; ++i) {
    int l = lines[i].second, r = lines[i].first;
    res -= cnt_l[l] + cnt_r[l] + cnt_r[r];
    res -= bit_l.sum(r - 1) - bit_l.sum(l);
    if (l > 0) res -= bit_r.sum(l - 1);    
    bit_l.add(l, 1LL);
    bit_r.add(r, 1LL);
    ++cnt_l[l];
    ++cnt_r[r];
  }

  std::cout << res << std::endl;
  return 0;             
}
