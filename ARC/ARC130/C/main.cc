#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  string a, b;
  cin >> a >> b;  
  vector<int> cnt_a(10, 0), cnt_b(10, 0);
  for (char c : a) ++cnt_a[c - '0'];
  for (char c : b) ++cnt_b[c - '0'];

  string res_a = a, res_b = b;
  int max_carry = 0;

  auto func = [&](int s0, int t0) -> void {
    int carry = 1;
    string s = "", t = "";
    vector<int> cnt_s = cnt_a, cnt_t = cnt_b;
    s += '0' + s0;
    t += '0' + t0;
    --cnt_s[s0];
    --cnt_t[t0];    
    for (int i = 1; i <= 9; ++i) {
      for (int j = max(9 - i, 1); j <= 9; ++j) {
        while (cnt_s[i] && cnt_t[j]) {
          --cnt_s[i];
          --cnt_t[j];
          ++carry;
          s += '0' + i;
          t += '0' + j;
        }
      }
    }    
    if (carry == (int)a.length()) carry += cnt_t[9];
    else if (carry == (int)b.length()) carry += cnt_s[9];    
    if (!chmax(max_carry, carry)) return;        
    for (int i = 9; i >= 1; --i) if (cnt_s[i]) s += string(cnt_s[i], '0' + i);
    for (int j = 9; j >= 1; --j) if (cnt_t[j]) t += string(cnt_t[j], '0' + j);    
    reverse(s.begin(), s.end());    
    reverse(t.begin(), t.end());    
    res_a = s;
    res_b = t;    
  };

  for (int i = 1; i <= 9; ++i) {
    for (int j = 10 - i; j <= 9; ++j) {
      if (cnt_a[i] && cnt_b[j]) func(i, j);
    }
  }  
  cout << res_a << endl << res_b << endl;
  return 0;
}
