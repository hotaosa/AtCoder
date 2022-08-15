#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  vector<int> cnt(14, 0);
  for (int i = 0; i < 5; ++i) {
    int n;
    cin >> n;
    ++cnt[n];
  }

  bool exist_two = false, exist_three = false;
  for (int c : cnt) {
    exist_two |= c == 2;
    exist_three |= c == 3;
  }

  cout << (exist_two && exist_three ? "Yes" : "No" ) << endl;  
  return 0;
}
