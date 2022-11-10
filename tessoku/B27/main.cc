#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  cout << a * b / __gcd(a, b) << endl;  
  return 0;
}
