#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s[0] == 'M') cout << 5 << endl;
  else if (s[0] == 'T' && s[1] == 'u') cout << 4 << endl;
  else if (s[0] == 'W') cout << 3 << endl;
  else if (s[0] == 'T' && s[1] == 'h') cout << 2 << endl;
  else cout << 1 << endl;  
  return 0;
}
