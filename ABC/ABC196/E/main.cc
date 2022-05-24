#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long low = -(1LL << 60);
  long long high = 1LL << 60;
  long long add = 0;

  for (int i = 0; i < n; ++i) {
    long long a;
    int t;
    cin >> a >> t;
    if (t == 1) {
      add += a;
      low += a;
      high += a;
    } else if (t == 2) {
      low = max(low, a);
      high = max(high, a);
    } else {
      low = min(low, a);
      high = min(high, a);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    long long x;
    cin >> x;    
    cout << min(high, max(low, x + add)) << endl;
  }  
  return 0;
}
