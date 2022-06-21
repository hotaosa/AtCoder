#include <iostream>

using namespace std;

bool is_pow10(long long n) {
  while (n % 10 == 0) n /= 10;
  return n == 1;
}

long long solve(long long n) {
  int d = to_string(n).length();
  long long res = 0;
  for (int i = 0; i < d - 1; ++i) res = res * 10 + 9;  

  for (int i = 1; i <= d / 2; ++i) {
    if (d % i) continue;    
    long long cur = 0;
    long long base = stoll(to_string(n).substr(0, i));
    for (int j = 0; j < d / i; ++j) {
      for (int k = 0; k < i; ++k) cur *= 10;
      cur += base;
    }
    if (cur <= n) res = max(res, cur);
    if (is_pow10(base)) continue;
    cur = 0;
    --base;
    for (int j = 0; j < d / i; ++j) {
      for (int k = 0; k < i; ++k) cur *= 10;
      cur += base;
    }
    if (cur <= n) res = max(res, cur);
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}