#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a > b) swap(a, b);

  vector<int> dp(n + 1, -1);
  auto func = [&](auto func, int k) -> int {
    if (dp[k] != -1) return dp[k];
    if (k < a) return dp[k] = 0;

    int res = func(func, k - a) ^ 1;
    if (k >= b) res |= func(func, k - b) ^ 1;
    return dp[k] = res;
  };

  cout << (func(func, n) ? "First" : "Second") << endl;
  return 0;
}
