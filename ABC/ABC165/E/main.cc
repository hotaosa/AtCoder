#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;  
  
  int o_mx = (m & 1 ? m : m - 1);
  int e_mx = (m & 1 ? m - 1 : m);

  for (int d = o_mx, l = 1; d >= 1; d -= 2, ++l) cout << l << " " << l + d << endl;
  for (int d = e_mx, l = o_mx + 2; d >= 2; d -= 2, ++l) cout << l << " " << l + d << endl;
  return 0;
}
