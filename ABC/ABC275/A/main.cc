#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  pair<int, int> res(-1, -1);
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    res = max(res, make_pair(h, i + 1));
  }
  cout << res.second << endl;  
  return 0;
}
