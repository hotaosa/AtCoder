#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n), b(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    sum += a[i];
  }

  vector<int> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] * 2 + b[i] > a[j] * 2 + b[j];
  });  

  int res = 0;
  for (int i = 0; i < n && sum >= 0; ++i) {
    ++res;
    sum -= a[order[i]] * 2 + b[order[i]];
  }

  cout << res << endl;    
  return 0;
}
