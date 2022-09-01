#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

void dfs(int n, string s, int sum, char nx) {
  if (sum == 0 && nx == ')') return;
  s += nx;
  sum += nx == '(' ? 1 : -1;
  if (s.size() == n) {
    if (sum == 0) cout << s << endl;
    return;
  }
  dfs(n, s, sum, '(');
  dfs(n, s, sum, ')');
}

int main() {
  int n;
  cin >> n;  
  dfs(n, "", 0, '(');
  return 0;
}
