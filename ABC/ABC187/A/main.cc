#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int func(int a) {
  int ret = 0;
  while (a) {
    ret += a % 10;
    a /= 10;
  }
  return ret;
}

int main() {
  int a, b;
  cin >> a >> b;  
  cout << max(func(a), func(b)) << endl;
  return 0;
}
