#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;

  int mx = -1, mn = w;
  for (int i = 1; w >= a * i; ++i) {
    if (w >= a * i && w <= b * i) {
      mx = max(mx, i);
      mn = min(mn, i);
    }
  }

  if (mx == -1) cout << "UNSATISFIABLE" << endl;
  else cout << mn << " " << mx << endl;  
  return 0;
}
