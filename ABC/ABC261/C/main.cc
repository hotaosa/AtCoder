#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;    
    if (mp[s]) cout << s << "(" << mp[s] << ")" << endl;
    else cout << s << endl;    
    ++mp[s];
  }
  return 0;
}