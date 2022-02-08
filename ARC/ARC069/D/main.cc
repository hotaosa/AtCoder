#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool judge(const string s, vector<int> &res, int first, int second) {
  int n = s.length();
  res[0] = (first? 1 : 0);
  res[1] = (second? 1 : 0);

  for (int i = 1; i < n - 1; ++i) {
    if (res[i]) {
      if (s[i] == 'o') res[i + 1] = res[i - 1];
      else res[i + 1] = 1 - res[i - 1];
    } else {
      if (s[i] == 'o') res[i + 1] = 1 - res[i - 1];
      else res[i + 1] = res[i - 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    int left = (i == 0 ? n - 1 : i - 1);
    int right = (i + 1) % n;
    if (res[i]) {
      if (s[i] == 'o' && res[left] != res[right]) return false;
      if (s[i] == 'x' && res[left] == res[right]) return false;
    } else {
      if (s[i] == 'o' && res[left] == res[right]) return false;
      if (s[i] == 'x' && res[left] != res[right]) return false;
    }
  }
  return true;  
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      vector<int> res(n, -1);
      if (judge(s, res, i, j)) {
        for (int i = 0; i < n; ++i) cout << (res[i] ? 'S' : 'W');
        cout << endl;
        return 0;
      }
    }
  }
  cout << "-1" << endl;  
  return 0;
}
