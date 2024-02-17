#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
using ld = long double;

int main() {
  cout << fixed << setprecision(10);

  int n;
  cin >> n;

  vector<ld> a(n + 1, 0.0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  vector<int> conv_idx;
  vector<ld> res(n);
  for (int i = n; i >= 0; --i) {
    while (conv_idx.size() > 1) {
      int siz = conv_idx.size();
      ld x = (a[conv_idx[siz - 1]] - a[i]) * (conv_idx[siz - 2] - i);
      ld y = (a[conv_idx[siz - 2]] - a[i]) * (conv_idx[siz - 1] - i);
      if (x <= y) {
        conv_idx.pop_back();
      } else {
        break;
      }
    }
    if (i < n) {
      int siz = conv_idx.size();
      res[i] = (a[conv_idx[siz - 1]] - a[i]) / (conv_idx[siz - 1] - i);
    }
    conv_idx.emplace_back(i);
  }

  for (int i = 0; i < n; ++i) {
    cout << res[i] << endl;
  }

  return 0;
}
