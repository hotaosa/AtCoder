#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(k);
  vector<bool> exist(n, false);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
    exist[--a[i]] = true;
  }

  while (q--) {
    int l;
    cin >> l;
    int p = a[--l];
    if (p == n - 1 || exist[p + 1]) continue;
    exist[p] = false;
    exist[p + 1] = true;
    ++a[l];
  }

  for (auto res : a) cout << res + 1 << " ";
  cout << endl;
  return 0;
}