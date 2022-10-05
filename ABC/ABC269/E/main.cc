#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  int l1 = 0, r1 = n;
  while (r1 - l1 > 1) {
    int m1 = (l1 + r1) / 2;
    cout << "? 1 " << m1 << " 1 " << n << endl;
    int cnt;
    cin >> cnt;
    if (cnt < m1) r1 = m1;
    else l1 = m1;
  }

  int l2 = 0, r2 = n;
  while (r2 - l2 > 1) {
    int m2 = (l2 + r2) / 2;
    cout << "? 1 " << n << " 1 " << m2 << endl;
    int cnt;
    cin >> cnt;
    if (cnt < m2) r2 = m2;
    else l2 = m2;
  }

  cout << "! " << r1 << " " << r2 << endl;  
  return 0;
}
