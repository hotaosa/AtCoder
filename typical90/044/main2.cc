#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  int shift = 0;
  auto pos = [&](int i) -> int {
    int ret = i - shift;
    if (ret < 0) ret += n;
    return ret;
  };

  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;    
    if (t == 1) swap(a[pos(--x)], a[pos(--y)]);
    if (t == 2) shift = (shift + 1) % n;
    if (t == 3) cout << a[pos(--x)] << endl;
  }  
  return 0;
}
