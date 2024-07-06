#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &e : a) cin >> e;
  sort(begin(a), end(a));

  int len = n - k;
  int res = a.back() - a[0];
  for (int i = 0; i <= k; ++i) {
    res = min(res, a[i + len - 1] - a[i]);
  }

  cout << res << endl;
  return 0;
}