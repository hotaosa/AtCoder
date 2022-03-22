#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

int main() {
  long long x, y;
  cin >> x >> y;

  map<long long, long long> memo;    

  auto solve = [&](auto solve, long long k) -> long long {
    if (memo.count(k)) return memo[k];
    if (k <= x) return memo[k] = x - k;
    if (k & 1) return memo[k] = min(k - x, min(solve(solve, (k + 1) / 2), solve(solve, (k - 1) / 2)) + 2);
    return memo[k] = min(k - x, solve(solve, k / 2) + 1);
  };

  cout << solve(solve, y) << endl;
  return 0;
}
