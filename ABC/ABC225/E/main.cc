#include <iostream>
#include <vector>
#include <algorithm>

struct Frac {
  long long t, b;
  Frac(long long t_, long long b_) : t(t_), b(b_) { }
  bool operator<(const Frac &other) const { return t * other.b < other.t * b; }
  bool operator<=(const Frac &other) const { return t * other.b <= other.t * b; }
};

int main() {
  int n;
  std::cin >> n;
  
  std::vector<std::pair<Frac, Frac> > vp;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    std::cin >> x >> y;
    Frac f1 = Frac(y, x - 1LL);
    Frac f2 = Frac(y - 1LL, x);
    vp.push_back(std::make_pair(f1, f2));
  }

  std::sort(vp.begin(), vp.end());
  int res = 0;
  Frac cur = Frac(0, 1);
  for (int i = 0; i < n; ++i) {
    if (cur <= vp[i].second) {
      ++res;
      cur = vp[i].first;
    }
  }

  std::cout << res << std::endl;
  return 0;
}
