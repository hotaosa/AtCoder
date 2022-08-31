#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int q;
  cin >> q;
  deque<int> dq;

  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) dq.push_front(x);
    if (t == 2) dq.push_back(x);
    if (t == 3) cout << dq[--x] << endl;
  }  
  return 0;
}
