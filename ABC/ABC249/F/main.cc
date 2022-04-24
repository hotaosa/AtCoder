#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  ++n;
  vector<int> t(n, 1);
  vector<long long> y(n, 0);  
  for (int i = 1; i < n; ++i) cin >> t[i] >> y[i];
  
  long long sum = 0, res = -(1LL << 60);
  priority_queue<int, vector<int> > pque;

  for (int i = n - 1; i >= 0 && k >= 0; --i) {
    if (t[i] == 1) {
      while((int)pque.size() > k) {
        sum += pque.top();
        pque.pop();
      }
      res = max(res, y[i] + sum);
      --k;
    } else {
      if (y[i] >= 0) sum += y[i];
      else pque.push(y[i]);
    }
  }
  cout << res << endl;
  return 0;
}
