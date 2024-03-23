#include <iostream>
#include <string>

using namespace std;

int Count(const string &s, const char &c) {
  int ret = 0;
  for (const auto &cc : s) {
    if (cc == c) {
      ++ret;
    };
  }
  return ret;
}

int main() {
  int w, b;
  cin >> w >> b;
  string s = "";
  for (int i = 0; i < 20; ++i) {
    s += "wbwbwwbwbwbw";
  }

  for (int i = 0; i < 12; ++i) {
    string t = s.substr(i, b + w);
    if (Count(t, 'w') == w && Count(t, 'b') == b) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}