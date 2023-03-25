#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n, k;
  string s;
  cin >> n >> k >> s;

  int cnt = 0;
  string res = "";
  for (auto c : s) {
    if (c == 'o' && cnt++ < k) {
      res += 'o';
    } else {
      res += 'x';
    }
  }

  cout << res << endl;
  return 0;
}
