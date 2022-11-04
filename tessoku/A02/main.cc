#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  
  bool exist = false;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    exist |= (a == x);
  }

  cout << (exist ? "Yes" : "No" ) << endl;  
  return 0;
}
