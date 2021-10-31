#include <iostream>
#include <vector>
#include <algorithm>

struct Str{
  std::string s;
  Str(std::string s_) : s(s_) { }
  bool operator<(const Str &another) const { return s + another.s < another.s + s; }
};

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<Str> vs;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    vs.push_back(Str(s));
  }
  std::sort(vs.begin(), vs.end());
  std::reverse(vs.begin(), vs.end());

  std::vector<std::vector<std::string> > dp(n, std::vector<std::string>(k + 1, ""));
  dp[0][1] = vs[0].s;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= std::min(k, i + 1); ++j) {
      if (dp[i - 1][j] == "") dp[i][j] = vs[i].s + dp[i - 1][j - 1];
      else dp[i][j] = std::min(dp[i - 1][j], vs[i].s + dp[i - 1][j - 1]);
    }
  }
  
  std::cout << dp[n - 1][k] << std::endl;  
  return 0;
}
