#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int q;
  cin >> q;
  deque<pair<long long, long long> > dq;
  while (q--) {
    int query;
    cin >> query;
    if (query == 1) {
      long long x, c;
      cin >> x >> c;
      dq.push_back({x, c});
    } else {
      long long c;
      cin >> c;
      long long res = 0;
      while (c) {
        auto fr = dq.front();
        dq.pop_front();
        long long cnt = min(c, fr.second);
        res += fr.first * cnt;
        c -= cnt;
        fr.second -= cnt;
        if (fr.second) dq.push_front(fr);
      }
      cout << res << endl;
    }
  }
  return 0;
}
