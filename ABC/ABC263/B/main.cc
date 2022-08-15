#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n, -1);
  for (int i = 1; i < n; ++i) { cin >> p[i]; --p[i]; }

  int res = 0, cur = n - 1;
  while (cur != 0) {
    ++res;
    cur = p[cur];
  }
  cout << res << endl;
  return 0;
}
