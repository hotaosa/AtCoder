#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  deque<int> dq;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    dq.push_back(a);
  }

  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) swap(dq[--x], dq[--y]);
    if (t == 2) {
      dq.push_front(dq.back());
      dq.pop_back();
    }
    if (t == 3) cout << dq[--x] << endl;
  }
  
  return 0;
}
