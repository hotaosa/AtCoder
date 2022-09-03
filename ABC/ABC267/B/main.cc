#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s[0] == '1') { cout << "No" << endl; return 0; }

  vector<bool> remain(7);
  remain[0] = s[6] == '1';
  remain[1] = s[3] == '1';
  remain[2] = s[1] == '1' || s[7] == '1';
  remain[3] = s[0] == '1' || s[4] == '1';
  remain[4] = s[2] == '1' || s[8] == '1';
  remain[5] = s[5] == '1';
  remain[6] = s[9] == '1';

  bool split = false;
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 2; j < 7; ++j) {
      if (remain[i] && remain[j]) {
        for (int k = i + 1; k < j; ++k) if (!remain[k]) split = true;
      }
    }
  }

  cout << (split ? "Yes" : "No" ) << endl;  
  return 0;
}
