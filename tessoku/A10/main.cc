#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 2, 0);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> left(n + 2, 0), right(n + 2, 0);
  for (int i = 1; i <= n + 1; ++i) left[i] = max(left[i - 1], a[i]);
  for (int i = n; i >= 0; --i) right[i] = max(right[i + 1], a[i]);

  int d;
  cin >> d;
  while (d--) {
    int l, r;
    cin >> l >> r;
    cout << max(left[--l], right[++r]) << endl;
  }
  
  return 0;
}
