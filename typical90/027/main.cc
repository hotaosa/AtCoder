#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  set<string> se;
  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    if (se.insert(s).second) res.push_back(i);
  }

  for (int r : res) cout << r << endl;  
  return 0;
}
