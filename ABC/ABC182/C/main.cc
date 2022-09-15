#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int digit(long long n) {
  int ret = 0;
  while (n) {
    ++ret;
    n /= 10;
  }
  return ret;
}

int main() {
  long long n;
  cin >> n;

  int d = digit(n);
  int res = d;
  for (int bit = 1; bit < (1 << d); ++bit) {
    int cnt = 0;
    long long nn = n, sum = 0;    
    for (int i = 0; i < d; ++i) {
      if (bit & (1 << i)) sum = sum * 10 + (nn % 10);
      else ++cnt;
      nn /= 10;
    }
    if (sum % 3 == 0) res = min(res, cnt);
  }

  cout << (res < d ? res : -1) << endl;  
  return 0;
}
