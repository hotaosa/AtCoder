#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;
  cout << (n >= -(1LL << 31) && n < (1LL << 31) ? "Yes" : "No") << endl;
  return 0;
}
