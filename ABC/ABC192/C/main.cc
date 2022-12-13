#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long func(long long n) {
  auto s = to_string(n);
  sort(s.begin(), s.end());
  auto t = s;
  reverse(t.begin(), t.end());
  return stoll(t) - stoll(s);
}

int main() {
  long long n;
  int k;
  cin >> n >> k;

  for (int i = 0; i < k; ++i) n = func(n);
  cout << n << endl;  
  return 0;
}
