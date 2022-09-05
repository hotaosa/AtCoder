#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto &p : h) cin >> p;

  auto all_zero = [&]() -> bool {
    for (int i = 0; i < n; ++i) if (h[i]) return false;
    return true;
  };

  int res = 0;
  while (!all_zero()) {
    ++res;
    int l = 0;
    while (h[l] == 0) ++l;
    int r = l + 1;
    while (r < n && h[r] > 0) ++r;
    for (int i = l; i < r; ++i) --h[i];
  }
  cout << res << endl;  
  return 0;
}
