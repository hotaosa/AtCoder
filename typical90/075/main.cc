#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;

  int cnt = 0;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ++cnt;
      n /= i;
    }    
  }
  if (n > 1) ++cnt;

  int res = 0;
  while (cnt > 1) {
    ++res;
    cnt = (cnt + 1) / 2;
  }

  cout << res << endl;  
  return 0;
}
