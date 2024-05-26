#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto &e : s) cin >> e;
  sort(begin(s), end(s));

  auto LcpLength = [&](int i, int j) -> int {
    int len = min(size(s[i]), size(s[j]));
    int ret = 0;
    for (int k = 0; k < len; ++k) {
      if (s[i][k] == s[j][k]) {
        ++ret;
      } else {
        break;
      }
    }
    return ret;
  };

  ll res = 0;
  for (int i = 0; i < n - 1; ++i) {
    int lcp = LcpLength(i, i + 1);
    for (int len = 1; len <= lcp; ++len) {
      int l = i + 1, r = n;
      while (r - l > 1) {
        int m = (l + r) / 2;
        (LcpLength(i, m) >= len ? l : r) = m;
      }
      res += l - i;
    }
  }

  cout << res << endl;
  return 0;
}