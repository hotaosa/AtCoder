#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  deque<int> dq;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    dq.push_back((p - i + n) % n);
  }
  sort(dq.begin(), dq.end());

  long long cur = 0;
  for (int i = 0; i < n; ++i) cur += min(dq[i], n - dq[i]);
  long long res = cur;
  
  int u = (n + 1) / 2;
  int l = n / 2;

  for (int i = 1; i <= n; ++i) {
    auto pu = lower_bound(dq.begin(), dq.end(), u);
    auto pl = lower_bound(dq.begin(), dq.end(), l);
    cur = cur - (dq.end() - pu) + (pl - dq.begin());
    res = min(res, cur);

    queue<int> que;
    while (!dq.empty() && dq.back() == n - i) {
      que.push(dq.back());
      dq.pop_back();
    }
    while (!que.empty()) {
      dq.push_front(-i);
      que.pop();
    }

    --u;
    --l;
  }

  cout << res << endl;  
  return 0;
}
