#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int d, n;
  cin >> d >> n;

  vector<int> cnt(d + 1);
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    ++cnt[--l];
    --cnt[r];
  }

  for (int i = 0; i < d; ++i) {
    if (i > 0) cnt[i] += cnt[i - 1];
    cout << cnt[i] << endl;
  }
  
  return 0;
}
