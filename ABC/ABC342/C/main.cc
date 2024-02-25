#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;

  map<char, char> mp;
  for (char c = 'a'; c <= 'z'; ++c) {
    mp[c] = c;
  }

  while (q--) {
    char c, d;
    cin >> c >> d;
    for (auto [k, v] : mp) {
      if (v == c) {
        mp[k] = d;
      }
    }
  }

  for (auto c : s) {
    cout << mp[c];
  }
  cout << endl;
  return 0;
}