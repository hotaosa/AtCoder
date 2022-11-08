#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  bool exist = false;
  for (int i = a; i <= b; ++i) {
    exist |= (100 % i == 0);
  }

  cout << (exist ? "Yes" : "No" ) << endl;  
  return 0;
}
