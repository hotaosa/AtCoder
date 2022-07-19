#include <iostream>
#include <map>

using namespace std;

int main() {
  map<char, int> mp;
  for (int i = 0; i < 3; ++i) {
    char c;
    cin >> c;
    ++mp[c];
  }
  for (auto m : mp) if (m.second == 1) { cout << m.first << endl; return 0; }
  cout << "-1" << endl;
  return 0;
}
