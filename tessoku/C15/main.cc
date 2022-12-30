#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    r[i] += k;
  }

  vector<int> order(n);
  iota(order.begin(), order.end(), 0);

  sort(order.begin(), order.end(), [&](int i, int j) {
    if (r[i] != r[j]) return r[i] < r[j];
    return l[i] < l[j];
  });

  vector<int> vl;
  int time = 0;;
  for (auto i : order) {
    if (l[i] >= time) {
      time = r[i];
      vl.push_back(time);
    }
  }

  sort(order.begin(), order.end(), [&](int i, int j) {
    if (l[i] != l[j]) return l[i] > l[j];
    return r[i] > r[j];
  });

  vector<int> vr;
  time = 1 << 30;
  for (auto i : order) {
    if (r[i] <= time) {
      time = l[i];
      vr.push_back(-time);
    }
  }

  for (int i = 0; i < n; ++i) {
    int cnt_l = upper_bound(vl.begin(), vl.end(), l[i]) - vl.begin();
    int cnt_r = upper_bound(vr.begin(), vr.end(), -r[i]) - vr.begin();
    cout << cnt_l + cnt_r + 1 << endl;
  }
  
  return 0;
}
