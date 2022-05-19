#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long t;
  cin >> n >> t;
  int n1 = n / 2, n2 = (n + 1) / 2;
  vector<long long> a1(n1), a2(n2);
  for (auto &p : a1) cin >> p;
  for (auto &p : a2) cin >> p;

  vector<long long> sum1, sum2;
  for (int bit = 0; bit < (1 << n1); ++bit) {
    long long sum = 0;
    for (int i = 0; i < n1; ++i) if (bit & (1 << i)) sum += a1[i];
    sum1.push_back(sum);
  }
  for (int bit = 0; bit < (1 << n2); ++bit) {
    long long sum = 0;
    for (int i = 0; i < n2; ++i) if (bit & (1 << i)) sum += a2[i];
    sum2.push_back(sum);
  }

  sort(sum1.begin(), sum1.end());
  sum1.erase(unique(sum1.begin(), sum1.end()), sum1.end());
  sort(sum2.begin(), sum2.end());
  sum2.erase(unique(sum2.begin(), sum2.end()), sum2.end());

  long long res = 0;
  for (auto s1 : sum1) {
    if (s1 > t) continue;
    auto p = upper_bound(sum2.begin(), sum2.end(), t - s1);
    if (p == sum2.begin()) continue;    
    res = max(res, s1 + *(--p));
  }
  cout << res << endl;
  return 0;
}
