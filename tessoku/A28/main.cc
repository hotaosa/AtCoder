#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  const int mod = 10000;

  int cur = 0;
  for (int i = 0; i < n; ++i) {
    char t;
    int a;
    cin >> t >> a;
    if (t == '+') cur = (cur + a) % mod;
    else if (t == '-') cur = (cur - a + mod) % mod;
    else cur = cur * a % mod;
    cout << cur << endl;
  }
  
  return 0;
}
