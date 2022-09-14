#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n), p(n);
  for (int i = 0; i < n; ++i) cin >> v[i] >> p[i];

  x *= 100;
  int res = 0, sum = 0;
  while (res < n && sum <= x) sum += v[res] * p[res++];  
  cout << (sum > x ? res : -1) << endl;
  return 0;
}
