#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;

  __int128_t x = a;
  __int128_t y = 1;
  for (int i = 0; i < b; ++i) y *= c;

  cout << (x < y ? "Yes" : "No" ) << endl;  
  return 0;
}
