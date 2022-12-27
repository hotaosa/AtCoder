#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> s(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    cout << s[i] - s[i - 1] << " ";
  }
  cout << endl;
  
  return 0;
}
