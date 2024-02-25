#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  for (auto &c : s) {
    ++mp[c];
  }

  for (int i = 0; i < (int)s.size(); ++i) {
    if (mp[s[i]] == 1) {
      cout << i + 1 << endl;
    }
  }

  return 0;
}