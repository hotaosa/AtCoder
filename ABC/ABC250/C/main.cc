#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> ball(n), pos(n);
  for (int i = 0; i < n; ++i) { ball[i] = i; pos[i] = i; }

  while (q--) {
    int x;
    cin >> x;
    int p1 = pos[--x];
    int p2 = (p1 == n - 1 ? p1 - 1 : p1 + 1);
    swap(ball[p1], ball[p2]);    
    swap(pos[ball[p1]], pos[ball[p2]]);    
  }

  for (auto &p : ball) cout << p + 1 << " ";
  cout << endl;  
  return 0;
}
