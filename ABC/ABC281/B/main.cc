#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool Sat(string s) {
  if (s.size() != 8 || s[0] < 'A' || s[0] > 'Z' || s[7] < 'A' || s[7] > 'Z') return false;
  try {
    int tmp = stoi(s.substr(1, 6));
    return tmp >= 100000 && tmp < 1000000;
  }
  catch(invalid_argument &e) {
    return false;
  }
}

int main() {
  string s;
  cin >> s;

  cout << (Sat(s) ? "Yes" : "No" ) << endl;
  return 0;
}
