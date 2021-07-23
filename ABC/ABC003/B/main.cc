#include <iostream>
#include <string>
#include <set>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int n = (int)s.length();

  std::set<char> se;
  se.insert('a');
  se.insert('t');
  se.insert('c');
  se.insert('o');
  se.insert('d');
  se.insert('e');
  se.insert('r');
  se.insert('@');

  bool possible = true;
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i]) continue;
    if (s[i] == '@' && se.count(t[i])) continue;
    if (t[i] == '@' && se.count(s[i])) continue;
    possible = false;
  }

  std::cout << (possible ? "You can win" : "You will lose") << std::endl;
  return 0;  
}
