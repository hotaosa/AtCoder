#include <iostream>
#include <string>
#include <deque>

int main() {
  std::string s;
  std::cin >> s;
  int n = (int)s.length();

  std::deque<char> dq;
  bool rev = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') rev = !rev;
    else if (rev) {
      if (!dq.empty() && s[i] == dq.front()) dq.pop_front();
      else dq.push_front(s[i]);
    } else {
      if (!dq.empty() && s[i] == dq.back()) dq.pop_back();
      else dq.push_back(s[i]);
    }
  }

  if (rev) {
    while (!dq.empty()) {
      std::cout << dq.back();
      dq.pop_back();
    }
  } else {
    while(!dq.empty()) {
      std::cout << dq.front();
      dq.pop_front();
    }
  }
  std::cout << std::endl;
  return 0;  
}
