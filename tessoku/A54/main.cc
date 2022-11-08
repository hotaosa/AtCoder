#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int q;
  cin >> q;
  
  map<string, int> mp;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      string name;
      int score;
      cin >> name >> score;
      mp[name] = score;
    } else {
      string name;
      cin >> name;
      cout << mp[name] << endl;
    }
  }
  
  return 0;
}
