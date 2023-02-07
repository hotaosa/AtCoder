#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;

  char c = 'A';
  --c;

  long long res = s[0] - c;
  for (int i = 1; i < (int)s.size(); ++i) {
    res = res * 26 + s[i] - c;
  }

  cout << res << endl;  
  return 0;
}
