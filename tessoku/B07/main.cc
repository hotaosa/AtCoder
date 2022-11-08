#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int t, n;
  cin >> t >> n;
  vector<int> cnt(t + 1, 0);

  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    ++cnt[l];
    --cnt[r];
  }

  for (int i = 0; i < t; ++i) {
    if (i > 0) cnt[i] += cnt[i - 1];
    cout << cnt[i] << endl;
  }
  
  return 0;
}
