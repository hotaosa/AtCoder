#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int k;
  cin >> k;
  int even = k / 2;
  int odd = (k + 1) / 2;
  cout << even * odd << endl;  
  return 0;
}
