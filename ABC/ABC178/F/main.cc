#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;

  bool possible = true;
  vector<int> cnt_a(n + 1, 0), cnt_sum(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    ++cnt_a[a[i]];
    if (++cnt_sum[a[i]] > n) possible = false;
    if (++cnt_sum[b[i]] > n) possible = false;
  }

  if (possible) {
    cout << "Yes" << endl;

    priority_queue<int, vector<int>, function<bool(int, int)> > pque(
      [&](int i, int j) {
        return cnt_sum[i] < cnt_sum[j];
      }
    );    
    for (int i = 1; i <= n; ++i) if (cnt_sum[i] > cnt_a[i]) pque.push(i);

    vector<int> res;
    for (int i = 0; i < n; ++i) {
      int x = pque.top();
      pque.pop();
      if (a[i] != x) {
        res.push_back(x);
        if (--cnt_sum[x] > cnt_a[x]) pque.push(x);
      } else {
        int y = pque.top();
        pque.pop();
        res.push_back(y);
        pque.push(x);
        if (--cnt_sum[y] > cnt_a[y]) pque.push(y);
      }
      --cnt_sum[a[i]];
      --cnt_a[a[i]];
    }

    assert((int)res.size() == n);
    for (auto r : res) cout << r << " ";
    cout << endl;    
  } else {
    cout << "No" << endl;
  }

  return 0;
}
