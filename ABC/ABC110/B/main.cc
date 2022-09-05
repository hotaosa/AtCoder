#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int mx_x = x, mn_y = y;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mx_x = max(mx_x, x);    
  }
  for (int i = 0; i < m; ++i) {
    int y;
    cin >> y;
    mn_y = min(mn_y, y);
  }
  cout << (mx_x < mn_y ? "No War" : "War") << endl;  
  return 0;
}
