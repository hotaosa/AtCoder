#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cnt(n, 0);
  int uni = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (++cnt[a] == 1) ++uni;
  }

  int a = -1, b = -1, x = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[i]) {
      if (a == -1) { a = i; x = cnt[i]; }
      else if (b == -1) b = i;
      else { cout << "No" << endl; return 0; }
    }
  }
  if (b - a > 1) { cout << "No" << endl; return 0; }  
  if (b == -1)  { cout << (a == n - 1 || a <= n / 2 ? "Yes" : "No" ) << endl; return 0; }
  cout << (b >= x + 1 && b <= x + (n - x) / 2 ? "Yes" : "No" ) << endl;
  return 0;
}
