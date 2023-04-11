#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n, l, r;
  cin >> n >> l >> r;

  int xsum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    xsum ^= (a % (l + r)) / l;
  }

  cout << (xsum ? "First" : "Second") << endl;
  return 0;
}
