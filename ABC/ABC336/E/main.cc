#include <iostream>
#include <vector>

using namespace std;

long long Solve(string s, int digit_sum) {
  const int n = s.length();
  vector dp(n + 1, vector(2, vector(digit_sum + 1, vector<long long>(digit_sum, 0))));
  dp[0][0][0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int less_than_s = 0; less_than_s < 2; ++less_than_s) {
      for (int cur_sum = 0; cur_sum <= digit_sum; ++cur_sum) {
        for (int cur_mod = 0; cur_mod < digit_sum; ++cur_mod) {
          for (int nx = 0; nx < 10 && cur_sum + nx <= digit_sum && (less_than_s || nx <= (s[i] - '0')); ++nx) {
            int nx_less_than_s = less_than_s | (nx < (s[i] - '0'));
            int nx_sum = cur_sum + nx;
            int nx_mod = (cur_mod * 10 + nx) % digit_sum;
            dp[i + 1][nx_less_than_s][nx_sum][nx_mod] += dp[i][less_than_s][cur_sum][cur_mod];
          }
        }
      }
    }
  }
  return dp[n][0][digit_sum][0] + dp[n][1][digit_sum][0];
}

int main() {
  string n;
  cin >> n;

  long long res = 0;
  for (int digit_sum = 1; digit_sum <= 9 * (int)n.length(); ++digit_sum) {
    res += Solve(n, digit_sum);
  }

  cout << res << endl;

  return 0;
}