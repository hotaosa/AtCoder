#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, k;
  cin >> n >> k;

  deque<long long> dq;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    dq.push_back(a);
  }
  sort(dq.begin(), dq.end());

  mint res = 1;
  if (k & 1 && dq.back() <= 0) {
    while (k--) { res *= dq.back(); dq.pop_back(); }
    cout << res.val() << endl;
    return 0;
  }

  while (k) {
    if (k == 1) { res *= dq.back(); dq.pop_back(); --k; }
    else if (dq[0] * dq[1] >= dq[dq.size() - 1] * dq[dq.size() - 2]) {
      for (int i = 0; i < 2; ++i) { res *= dq.front(); dq.pop_front(); }
      k -= 2;
    } else { res *= dq.back(); dq.pop_back(); --k; }
  }
  cout << res.val() << endl;  
  return 0;
}
