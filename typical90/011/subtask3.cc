#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
  int d, c;
  long long s;
  Job(int d_, int c_, long long s_) : d(d_), c(c_), s(s_) { }
  bool operator<(const Job &another) const {
    return d < another.d;
  }
};

template<class T> void chmax(T &a, T b) { a = std::max(a, b); }

int main() {
  int n;
  std::cin >> n;
  
  std::vector<Job> jobs;
  int d_max = 0;
  for (int i = 0; i < n; ++i) {
    int d, c;
    long long s;
    std::cin >> d >> c >> s;
    chmax(d_max, d);
    jobs.push_back(Job(d, c, s));    
  }
  std::sort(jobs.begin(), jobs.end());

  std::vector<std::vector<long long> > dp(n + 1, std::vector<long long>(d_max + 1, 0LL));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= d_max; ++j) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j + jobs[i].c <= jobs[i].d) chmax(dp[i + 1][j + jobs[i].c], dp[i][j] + jobs[i].s);
    }
  }

  long long res = 0LL;
  for (auto r : dp[n]) chmax(res, r);
  std::cout << res << std::endl;
  return 0;
}
