#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long a, b;
  cin >> n >> a >> b;
  vector<long long> h(n);
  for (auto &p : h) cin >> p;

  auto judge = [&](int k) -> bool {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      if (h[i] - b * k > 0) sum += (h[i] - b * k + a - b - 1) / (a - b);      
    }
    if (sum > k) return false;
    return true;
  };

  int l = 0, r = (int)1e9;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (judge(m)) r = m;
    else l = m;
  }

  cout << r << endl;
  return 0;
}
