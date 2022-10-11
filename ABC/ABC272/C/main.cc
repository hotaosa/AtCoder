#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> even, odd;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    (a & 1 ? odd : even).push_back(a);
  }
  
  int res = -1;
  if (odd.size() > 1) {
    sort(odd.rbegin(), odd.rend());
    res = max(res, odd[0] + odd[1]);
  }
  if (even.size() > 1) {
    sort(even.rbegin(), even.rend());
    res = max(res, even[0] + even[1]);
  }

  cout << res << endl;  
  return 0;
}
