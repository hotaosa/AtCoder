#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x;
  string a;
  cin >> n >> x >> a;
  a[--x] = '@';

  int y = x;
  while (y > 0 && a[--y] == '.') a[y] = '@';
  y = x;
  while (y < n - 1 && a[++y] == '.') a[y] = '@';

  cout << a << endl;  
  return 0;
}
