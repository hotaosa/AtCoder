#include <iostream>

using namespace std;

long long rev(long long x) {
  long long ret = 0;
  while (x) {
    ret = ret * 10 + x % 10;
    x /= 10;
  }
  return ret;
}

long long f(long long x) {  
  long long y = rev(x);
  if (y >= x) return x;
  else return f(y);
}

int main() {
  long long n, k;
  cin >> n >> k;

  long long k2 = rev(k);
  int res = 0;
  if (f(k) == k) {
    if (k2 != k) while (k2 <= n) { ++res; k2 *= 10; }
    while (k <= n) { ++res; k *= 10; }    
  }
  cout << res << endl;
}