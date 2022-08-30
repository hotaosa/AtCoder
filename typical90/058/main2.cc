#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int func(int x) {
  int y = x;
  while (x) {
    y += x % 10;
    x /= 10;
  }
  return y % 100000;
}

int main() {
  int n;
  long long k;
  cin >> n >> k;

  vector<int> cnt(100000, -1);
  cnt[n] = 0;
  int cur = 0;
  while (k--) {
    ++cur;
    n = func(n);    
    if (cnt[n] != -1) {
      int loop_len = cur - cnt[n];
      k %= loop_len;  
    } else {
      cnt[n] = cur;
    }
  }
  cout << n << endl;
  return 0;
}
