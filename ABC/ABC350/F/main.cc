#include <cctype>
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  map<int, int> mp;
  stack<int> st;
  for (int i = 0; i < (int)size(s); ++i) {
    if (s[i] == '(') {
      st.push(i);
    } else if (s[i] == ')') {
      mp[st.top()] = i;
      mp[i] = st.top();
      st.pop();
    } else {
      if (size(st) & 1) {
        s[i] = isupper(s[i]) ? tolower(s[i]) : toupper(s[i]);
      }
    }
  }

  string res = "";
  auto Solve = [&](auto Solve, int cur, int e, int d) -> void {
    while (cur != e) {
      if (isalpha(s[cur])) {
        res += s[cur];
      } else {
        Solve(Solve, mp[cur] - d, cur, d * -1);
        cur = mp[cur];
      }
      cur += d;
    }
  };

  Solve(Solve, 0, size(s), 1);
  cout << res << endl;
  return 0;
}
