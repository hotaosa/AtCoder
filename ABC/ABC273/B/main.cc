#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long round(long long x, int d) {
  for (int i = 0; i < d; ++i) x /= 10;
  if (x % 10 >= 5) x += 10 - (x % 10);
  else x -= (x % 10);
  for (int i = 0; i < d; ++i) x *= 10;
  return x;
}

int main() {
  long long x;
  int k;
  cin >> x >> k;
  for (int i = 0; i < k; ++i) x = round(x, i);
  cout << x << endl;  
  return 0;
}
