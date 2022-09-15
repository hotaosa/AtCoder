#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  deque<char> dq;
  for (auto c : s) dq.push_back(c);

  bool rev = false;

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) rev = !rev;
    else {
      int f;
      char c;
      cin >> f >> c;
      if (f == 1) {
        if (rev) dq.push_back(c);
        else dq.push_front(c);
      } else {
        if (rev) dq.push_front(c);
        else dq.push_back(c);
      }
    }
  }

  if (rev) {
    while (!dq.empty()) {
      cout << dq.back();
      dq.pop_back();
    }
  } else {
    while (!dq.empty()) {
      cout << dq.front();
      dq.pop_front();
    }  
  }
  cout << endl;  
  return 0;
}
