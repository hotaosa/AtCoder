#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  string t = s;
  sort(t.begin(), t.end());
  cout << (s == t ? "Yes\n" : "No\n");
  return 0;
}