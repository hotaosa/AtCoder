#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  s.pop_back();
  s += '4';
  cout << s << endl;
  return 0;
}