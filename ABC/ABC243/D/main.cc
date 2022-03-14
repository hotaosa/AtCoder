#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long x;
  string s;
  cin >> n >> x >> s;

  stack<char> st1, st2;
  for (int i = 0; i < n; ++i)  {
    if (s[i] != 'U') st1.push(s[i]);
    else if (!st1.empty() && st1.top() != 'U') st1.pop();
    else st1.push('U');
  }
  while (!st1.empty()) {
    st2.push(st1.top());
    st1.pop();
  }
  while (!st2.empty()) {
    char c = st2.top();
    st2.pop();
    if (c == 'L') x *= 2;
    else if (c == 'R') x = x * 2 + 1;
    else x /= 2;
  }
  cout << x << endl;
  return 0;
}
