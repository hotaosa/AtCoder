#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) { cin >> p; --p; }

  long long res = 0, cnt_same = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == i) ++cnt_same;
    if (a[i] > i && a[a[i]] == i) ++res;
  }
  res += cnt_same * (cnt_same - 1) / 2;
  cout << res << endl;
  return 0;
}
