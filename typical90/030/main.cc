#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<int> cnt(n + 1, 0);
  int res = 0;

  for (int i = 2; i <= n; ++i) {
    if (!is_prime[i]) continue;
    for (int j = i; j <= n; j += i) {
      if (++cnt[j] == k) ++res;
      if (j > i) is_prime[j] = false;      
    }
  }

  cout << res << endl;  
  return 0;
}
