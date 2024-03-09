#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  bool valid = true;
  for (auto &c : s) {
    if (c == '|') {
      valid = !valid;
    } else if (valid) {
      cout << c;
    }
  }
  cout << endl;
  return 0;
}