#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

string convert(string s, int from, int to) {
  long long num = 0;
  for (char c : s) num = num * from + (c - '0');
  string ret = "";
  if (num == 0) return "0";
  while (num) {
    ret += '0' + (num % to);
    num /= to;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
  string s;
  int k;
  cin >> s >> k;
  while (k--) {
    s = convert(s, 8, 9);    
    for (char &c : s) if (c == '8') c = '5';        
  }  
  cout << s << endl;
  return 0;
}
