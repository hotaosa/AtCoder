#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  string str = "0123456789ABCDEF";
  cout << str[n / 16] << str[n % 16] << endl;  
  return 0;
}
