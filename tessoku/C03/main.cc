#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int d;
  long long x;
  cin >> d >> x;

  vector<long long> p(d);
  p[0] = x;

  for (int i = 1; i < d; ++i) {
    cin >> p[i];
    p[i] += p[i - 1];
  }

  int q;
  cin >> q;
  while (q--) {
    int s, t;
    cin >> s >> t;
    if (p[--s] == p[--t]) {
      cout << "Same" << endl;
    } else if (p[s] > p[t]) {
      cout << s + 1 << endl;
    } else {
      cout << t + 1 << endl;
    }
  }  
  
  return 0;
}
