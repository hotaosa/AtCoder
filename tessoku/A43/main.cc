#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, l;
  cin >> n >> l;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    char b;
    cin >> a >> b;
    if (b == 'E') res = max(res, l - a);
    else res = max(res, a);
  }

  cout << res << endl;  
  return 0;
}
