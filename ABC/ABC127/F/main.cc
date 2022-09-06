#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
const long long INF = 1LL << 60;

int main() {
  priority_queue<long long, vector<long long> > pque_l;
  priority_queue<long long, vector<long long>, greater<> > pque_r;
  pque_l.push(-INF);
  pque_r.push(INF);
  long long res = 0;

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      long long a, b;
      cin >> a >> b;
      res += b;
      pque_l.push(a);
      pque_r.push(a);
      auto l = pque_l.top();
      auto r = pque_r.top();
      if (l > r) {
        res += l - r;
        pque_l.pop();
        pque_r.pop();
        pque_l.push(r);
        pque_r.push(l);
      }
    } else {
      cout << pque_l.top() << " " << res << endl;
    }
  }
  return 0;
}
