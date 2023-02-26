#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "For") ++cnt;
  }

  cout << (cnt * 2 > n ? "Yes" : "No" ) << endl;  
  return 0;
}
