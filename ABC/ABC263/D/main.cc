#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long l, r;
  cin >> n >> l >> r;
  vector<long long> a(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  vector<long long> left(n + 1, 0), right(n + 1, 0);
  for (int i = 1; i <= n; ++i) left[i] = left[i - 1] + a[i - 1] - l;
  for (int i = n - 1; i >= 0; --i) right[i] = right[i + 1] + a[i] - r;
  for (int i = n - 1; i >= 0; --i) right[i] = max(right[i], right[i + 1]);

  long long res = sum;
  for (int i = 0; i <= n; ++i) res = min(res, sum - left[i] - right[i]);
  cout << res << endl;    
  return 0;
}
