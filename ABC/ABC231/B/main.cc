#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {  
  int n;
  cin >> n;
  map<string, int> ma;
  int get = 0;
  string res = "";

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (chmax(get, ++ma[s])) res = s;
  }

  cout << res << endl;
  return 0;
}
