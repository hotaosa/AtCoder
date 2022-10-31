#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long func(long long n, map<long long, long long> &mp) {
  if (n == 0) return 1;
  if (mp.count(n)) return mp[n];
  return mp[n] = func(n / 2, mp) + func(n / 3, mp);
}

int main() {
  long long n;
  cin >> n;

  map<long long, long long> mp;
  cout << func(n, mp) << endl;  
  return 0;
}
