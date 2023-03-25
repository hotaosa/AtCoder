#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  for (auto c : s) {
    cout << (c == '1' ? 0 : 1);
  }
  cout << endl;  
  return 0;
}
