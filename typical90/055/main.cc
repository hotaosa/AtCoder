#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long p, q;
  cin >> n >> p >> q;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  int res = 0;
  for (int i = 0; i < n - 4; ++i) {    
    for (int j = i + 1; j < n - 3; ++j) {
      for (int k = j + 1; k < n - 2; ++k) {
        for (int l = k + 1; l < n - 1; ++l) {
          for (int m = l + 1; m < n; ++m) {
            if (a[i] * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q) ++res;
          }
        }
      }
    }
  }

  cout << res << endl;  
  return 0;
}
