#include <iostream>
#include <vector>

using namespace std;

vector<string> Split(const string &s, char delimiter) {
  vector<string> ret;
  string cur = "";
  for (const auto &c : s) {
    if (c == delimiter) {
      if (cur != "") {
        ret.emplace_back(cur);
        cur = "";
      }
    } else {
      cur += c;
    }
  }
  if (cur != "") {
    ret.emplace_back(cur);
  }
  return ret;
}

int main() {
  string s;
  cin >> s;
  cout << Split(s, '.').back() << endl;
  return 0;
}