#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  int res = 0;
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    res += count(s.begin(), s.end(), '#');
  }

  cout << res << endl;  
  return 0;
}
