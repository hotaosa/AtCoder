#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long sum = 0;
  vector<long long> a(n * 2);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];    
    sum += a[i];
    a[i] *= 10;
  }
  for (int i = n; i < n * 2; ++i) a[i] = a[i - n];
  for (int i = 1; i < n * 2; ++i) a[i] += a[i - 1];

  for (int i = 0; i < n; ++i) {
    auto p = lower_bound(a.begin(), a.end(), a[i] + sum);
    if (*p == a[i] + sum) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
