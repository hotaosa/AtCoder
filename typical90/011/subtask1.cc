#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
  int d, c;
  long long s;
  Job(int d_, int c_, long long s_) : d(d_), c(c_), s(s_) { }
  bool operator<(const Job &another) const{
    if (s != another.s) return s < another.s;
    if (d != another.d) return d < another.d;
    return c < another.c;
  }
};

int main() {
  int n;
  std::cin >> n;
  if (n > 8) return 0;
  
  std::vector<Job> jobs;
  for (int i = 0; i < n; ++i) {
    int d, c;
    long long s;
    std::cin >> d >> c >> s;
    jobs.push_back(Job(d, c, s));    
  }
  std::sort(jobs.begin(), jobs.end());

  long long res = 0LL;
  do {
    long long cur = 0LL;
    int day = 0;
    for (int i = 0; i < n; ++i) {
      if (day + jobs[i].c <= jobs[i].d) {
        day += jobs[i].c;
        cur += jobs[i].s;
      }
    }
    res = std::max(res, cur);
  } while (std::next_permutation(jobs.begin(), jobs.end()));

  std::cout << res << std::endl;
  return 0;
}
