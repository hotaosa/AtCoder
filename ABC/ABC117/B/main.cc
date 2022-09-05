#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0, mx = 0;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    sum += l;
    mx = max(mx, l);
  }
  cout << (mx < sum - mx ? "Yes" : "No" ) << endl;  
  return 0;
}
