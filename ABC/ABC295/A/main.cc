#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  unordered_set<string> se = {"and", "not", "that", "the", "you"};

  int n;
  cin >> n;

  bool exist = false;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    exist |= se.count(s);
  }

  cout << (exist ? "Yes" : "No" ) << endl;
  return 0;
}
