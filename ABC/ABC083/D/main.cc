#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  auto judge = [&](int k) -> bool {
    bool exist_zero = false, exist_one = false;
    vector<bool> needs_check(n, true);
    for (int i = k; i < n; ++i) needs_check[i] = false;
    for (int i = n - k - 1; i >= 0; --i) needs_check[i] = false;
    for (int i = 0; i < n; ++i) {
      if (needs_check[i] && s[i] == '0') exist_zero = true;
      if (needs_check[i] && s[i] == '1') exist_one = true;
    }
    if (exist_zero && exist_one) return false;
    else return true;
  };

  int l = 1, r = n + 1;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (judge(m)) l = m;
    else r = m;
  }
  cout << l << endl;  
  return 0;
}
