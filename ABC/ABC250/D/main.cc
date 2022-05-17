#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;
  
  constexpr int SIZ = 1000001;
  vector<bool> is_prime(SIZ, true);
  vector<long long> prime_list;
  for (long long i = 2; i * i * i <= n; ++i) {
    if (!is_prime[i]) continue;
    prime_list.push_back(i);
    for (long long j = i * 2; j < SIZ; j += i) is_prime[j] = false;    
  }

  int res = 0;
  for (auto pn : prime_list) {
    long long div = min(n / (pn * pn * pn), pn - 1);
    res += upper_bound(prime_list.begin(), prime_list.end(), div) - prime_list.begin();
  }
  cout << res << endl;
  return 0;
}
