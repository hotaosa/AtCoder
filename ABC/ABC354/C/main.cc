#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> c[i];
  }

  vector<int> order(n);
  iota(begin(order), end(order), 0);
  sort(begin(order), end(order), [&](int i, int j) {
    return make_pair(c[i], -a[i]) < make_pair(c[j], -a[j]);
  });

  vector<int> res;
  int cur_max = 0;
  for (int i : order) {
    if (a[i] > cur_max) {
      cur_max = a[i];
      res.emplace_back(i);
    }
  }

  sort(begin(res), end(res));
  cout << size(res) << endl;
  for (auto r : res) cout << r + 1 << " ";
  cout << endl;

  return 0;
}
