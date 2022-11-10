#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      cout << i << endl;
      for (int j = i * 2; j <= n; j += i) is_prime[j] = false;
    }
  }
  
  return 0;
}
