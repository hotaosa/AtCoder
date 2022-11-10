#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  int xsum = 0;
  int grundy[] = {0, 0, 1, 1, 2};

  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    xsum ^= grundy[a % 5];
  }

  cout << (xsum ? "First" : "Second") << endl;  
  return 0;
}
