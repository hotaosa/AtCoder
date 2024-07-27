#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &e : a) cin >> e;
  sort(begin(a), end(a));

  auto Judge = [&a](int x, int d, int k) -> bool {
    auto itl = lower_bound(begin(a), end(a), x - d);
    auto itr = upper_bound(begin(a), end(a), x + d);
    return itr - itl >= k;
  };

  auto Solve = [&Judge](int x, int k) -> int {
    int l = -1, r = 1 << 30;
    while (r - l > 1) {
      int m = (l + r) / 2;
      (Judge(x, m, k) ? r : l) = m;
    }
    return r;
  };

  while (q--) {
    int b, k;
    cin >> b >> k;
    cout << Solve(b, k) << endl;
  }

  return 0;
}