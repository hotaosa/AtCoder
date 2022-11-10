#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;

  int digit = to_string(n).size();
  
  vector<long long> pow10(digit + 1, 1);
  for (int i = 1; i <= digit; ++i) pow10[i] = pow10[i - 1] * 10;

  vector<int> d(digit + 1, 0);  
  for (int i = 1; i <= digit; ++i) d[i] = n / pow10[i - 1] % 10;  

  long long res = 0;
  for (int i = 1; i <= digit; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (j < d[i]) res += (n / pow10[i] + 1) * pow10[i - 1] * j;
      if (j == d[i]) res += (n / pow10[i] * pow10[i - 1] + n % pow10[i - 1] + 1) * j;
      if (j > d[i]) res += n / pow10[i] * pow10[i - 1] * j;
    }
  }

  cout << res << endl;  
  return 0;
}
