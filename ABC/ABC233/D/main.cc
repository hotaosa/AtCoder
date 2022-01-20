#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k;  
  cin >> n >> k;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;
  for (int i = 1; i < n; ++i) a[i] += a[i - 1];
  map<long long, long long> ma;
  ma[0] = 1;

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += ma[a[i] - k];
    ++ma[a[i]];
  }

  cout << res << endl;
  return 0;
}
