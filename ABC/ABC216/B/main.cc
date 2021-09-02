#include <iostream>
#include <string>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<std::string, std::string> > names;
  for (int i = 0; i < n; ++i) {
    std::string s, t;
    std::cin >> s >> t;
    names.push_back(std::make_pair(s, t));
  }

  bool exist = false;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (names[i] == names[j]) exist = true;
    }
  }

  std::cout << (exist ? "Yes" : "No") << std::endl;
  return 0;
}
