#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;



int main() {
  int n;
  cin >> n;
  vector<int> pre(n), in(n), in_inv(n);
  for (auto &p : pre) { cin >> p; --p; }
  for (auto &p : in) { cin >> p; --p; }
  for (int i = 0; i < n; ++i) in_inv[in[i]] = i;

  vector<int> ch_l(n, 0), ch_r(n, 0);

  auto func = [&](auto func, int lp, int li, int siz) -> bool {    
    int root = pre[lp];
    int pos_root = in_inv[root];
    if (pos_root < li || pos_root >= li + siz) return false;

    int siz_l = pos_root - li;
    int siz_r = li + siz - 1 - pos_root;

    if (siz_l > 0) {
      ch_l[root] = pre[lp + 1] + 1;
      if (!func(func, lp + 1, li, siz_l)) return false;
    }
    if (siz_r > 0) {
      ch_r[root] = pre[lp + 1 + siz_l] + 1;
      if (!func(func, lp + 1 + siz_l, pos_root + 1, siz_r)) return false;
    }
    return true;
  };

  if (func(func, 0, 0, n) && pre[0] == 0) {
    for (int i = 0; i < n; ++i) cout << ch_l[i] << " " << ch_r[i] << endl;
  } else {
    cout << "-1" << endl;
  }    
  return 0;
}
