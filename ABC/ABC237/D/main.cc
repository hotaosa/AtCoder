#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Node {
  int left, right;
  Node() : left(-1), right(-1) { }
};

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<Node> v(n + 1, Node());
  int head = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      v[i + 1].right = i;
      v[i + 1].left = v[i].left;
      v[i].left = i + 1;
      if (v[i + 1].left == -1) head = i + 1;
      else v[v[i + 1].left].right = i + 1;
    } else {
      v[i + 1].left = i;
      v[i + 1].right = v[i].right;
      v[i].right = i + 1;
      if (v[i + 1].right != -1) v[v[i + 1].right].left = i + 1;
    }
  }

  int cur = head;
  cout << cur;
  while (v[cur].right != -1) {
    cur = v[cur].right;
    cout << " " << cur;
  }
  cout << endl;  
  return 0;
}
