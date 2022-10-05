#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;

  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  auto judge = [&](long long m) -> bool {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += min(a[i], m);
    }
    return sum < k;
  };

  long long l = 0, r = 1LL << 60;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (judge(m)) l = m;
    else r = m;
  }

  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += min(a[i], l);
    a[i] -= min(a[i], l);
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      ++cnt;
      --a[i];
    }
    if (cnt == k) break;
  }

  for (int i = 0; i < n; ++i) cout << a[i] << " ";
  cout << endl;  
  return 0;
}
