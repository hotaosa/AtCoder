#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> used(2 * n + 2, false);
  while (true) {
    for (int i = 1; i <= 2 * n + 1; ++i) {
      if (!used[i]) {
        used[i] = true;
        cout << i << endl;
        break;
      }
    }
    int x;
    cin >> x;
    if (x == 0) return 0;
    else used[x] = true;    
  }
  return 0;
}
