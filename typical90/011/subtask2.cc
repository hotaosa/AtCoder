#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
  int d, c;
  long long s;
  Job(int d_, int c_, long long s_) : d(d_), c(c_), s(s_) { }
  bool operator<(const Job &another) const{
    if (d != another.d) return d < another.d;
    if (s != another.s) return s > another.s;
    return c < another.c;
  }
};

int main() {
  int n;
  std::cin >> n;
  if (n > 20) return 0;
  
  std::vector<Job> jobs;
  for (int i = 0; i < n; ++i) {
    int d, c;
    long long s;
    std::cin >> d >> c >> s;
    jobs.push_back(Job(d, c, s));    
  }
  std::sort(jobs.begin(), jobs.end());

  long long res = 0LL;
  for (int bit = 1; bit < (1 << n); ++bit) {
    long long cur = 0LL;
    int day = 0;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        if (day + jobs[i].c <= jobs[i].d) {
          day += jobs[i].c;
          cur += jobs[i].s;
        }
      }
    }
    res = std::max(res, cur);
  }

  std::cout << res << std::endl;
  return 0;
}
