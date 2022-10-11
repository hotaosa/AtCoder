#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;

  string str = t + t + string(n, 'z') + s + s;
  auto sa = atcoder::suffix_array(str);

  long long res = 0;
  int cnt = n;
  for (auto i : sa) {
    if (i < n) --cnt;
    if (i >= 3 * n && i < 4 * n) res += cnt;
  }

  cout << res << endl;  
  return 0;
}
