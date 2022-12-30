#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  cout << n << endl;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    cout << i + 1 << " " << j + 1 << endl;
  }
    
  return 0;
}
