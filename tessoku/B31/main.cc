#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;

  long long res = n / 3 + n / 5 + n / 7;
  res -= n / 15 + n / 21 + n / 35;
  res += n / 105;
  cout << res << endl;  
  return 0;
}
