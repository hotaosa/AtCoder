#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a_mx = 0, b_mn = 1000;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    a_mx = max(a_mx, a);
  }
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    b_mn = min(b_mn, b);
  }

  cout << max(0, b_mn - a_mx + 1) << endl;  
  return 0;
}
