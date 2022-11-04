#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int q;
  cin >> q;
  vector<int> x(q);
  int mx = 0;
  for (auto &p : x) { cin >> p; mx = max(mx, p); }

  vector<bool> is_prime(mx + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= mx; ++i) {
    if (!is_prime[i]) continue;
    for (int j = i * 2; j <= mx; j += i) is_prime[j] = false;
  }

  for (int i = 0; i < q; ++i) cout << (is_prime[x[i]] ? "Yes" : "No" ) << endl;  
  return 0;
}
