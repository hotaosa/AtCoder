#include <iostream>
#include <vector>
#include <algorithm>

struct balloon {
  long long h, s;
  balloon(long long h_, long long s_) : h(h_), s(s_) { }
};

bool possible(const std::vector<balloon> &vb, long long v) {
  std::vector<long long> t;
  int n = (int)vb.size();
  for (int i = 0; i < n; ++i) {
    if (vb[i].h > v) return false;
    t.push_back((v - vb[i].h) / vb[i].s);
  }
  std::sort(t.begin(), t.end());
  for (int i = 0; i < n; ++i) if (t[i] < i) return false;
  return true;
}

int main() {
  const long long INF = 1LL << 60;
  
  int n;
  std::cin >> n;
  std::vector<balloon> vb;
  for (int i = 0; i < n; ++i) {
    long long h, s;
    std::cin >> h >> s;
    vb.push_back(balloon(h, s));
  }

  long long r = INF, l = 0LL;
  while (r - l > 1) {
    long long mid = (r + l) / 2LL;
    if (possible(vb, mid)) r = mid;
    else l = mid;
  }
  std::cout << r << std::endl;
  return 0;
}
