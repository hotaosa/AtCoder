#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool Judge1(const string &s) {
  int x = 0;
  for (int i = 0; i < 8; ++i) {
    if (s[i] == 'B') x ^= i & 1;
  }
  return x == 1;
}

bool Judge2(const string &s) {
  bool found = false;
  for (auto &c : s) {
    if (c == 'R') {
      found = !found;
    } else if (c == 'K') {
      return found;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  string s;
  cin >> s;
  cout << (Judge1(s) && Judge2(s) ? "Yes" : "No" ) << endl;
  return 0;
}
