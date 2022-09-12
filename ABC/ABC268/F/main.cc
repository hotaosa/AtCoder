#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> vs(n);
  for (auto &p : vs) cin >> p;

  vector<long long> sum(n, 0), cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    for (auto c : vs[i]) {
      if (c == 'X') ++cnt[i];
      else sum[i] += c - '0';
    }
  }

  vector<int> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;
  sort(order.begin(), order.end(), [&](int i, int j) {
    return sum[i] * cnt[j] < sum[j] * cnt[i];
  });

  string str = "";
  for (int i : order) str += vs[i];

  long long res = 0, cnt_x = 0;
  for (auto c : str) {
    if (c == 'X') ++cnt_x;
    else res += (c - '0') * cnt_x;
  }
  cout << res << endl;  
  return 0;
}
