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

void chmax(long long &a, long long b) { if (a < b) a = b; }

int main() {
  int n;
  std::cin >> n;
  std::vector<Job> vj;
  int ma = 0;
  vj.push_back(Job(0, 0, 0LL));
  for (int i = 0; i < n; ++i) {
    int d, c;
    long long s;
    std::cin >> d >> c >> s;
    ma = std::max(ma, d);
    vj.push_back(Job(d, c, s));
  }
  std::sort(vj.begin(), vj.end());
  
  std::vector<std::vector<long long> > dp(n + 1, std::vector<long long>(ma + 1, 0LL));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= ma; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j <= vj[i].d && j >= vj[i].c) chmax(dp[i][j],  dp[i - 1][j - vj[i].c] + vj[i].s);
    }    
  }

  long long res = 0LL;
  for (int i = 0; i <= ma; ++i) res = std::max(res, dp[n][i]);
  std::cout << res << std::endl;
  return 0;
}
