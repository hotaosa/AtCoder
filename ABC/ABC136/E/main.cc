#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int sum = 0;
  for (auto &p : a) { cin >> p; sum += p; }

  vector<int> divisor;
  for (int i = 1; i * i <= sum; ++i) {
    if (sum % i == 0) {
      divisor.push_back(i);
      if (sum / i != i) divisor.push_back(sum / i);
    }
  }  

  int res = 0;
  for (int d : divisor) {
    vector<int> mod(n);
    for (int i = 0; i < n; ++i) mod[i] = a[i] % d;
    sort(mod.begin(), mod.end());
    vector<int> sum1(n), sum2(n);
    sum1[0] = mod[0];
    sum2[n - 1] = (d - mod[n - 1]) % d;
    for (int i = 1; i < n; ++i) sum1[i] = sum1[i - 1] + mod[i];
    for (int i = n - 2; i >= 0; --i) sum2[i] = sum2[i + 1] + (d - mod[i]) % d;
    for (int i = 0; i < n - 1 && sum1[i] <= k; ++i) if (sum1[i] == sum2[i + 1]) res = max(res, d);
  }
  cout << res << endl;
  return 0;
}
