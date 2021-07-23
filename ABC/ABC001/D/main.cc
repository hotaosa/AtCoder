#include <iostream>
#include <string>
#include <vector>

int func(std::string s, bool roundup) {
  int hour = (s[0] - '0') * 10 + (s[1] - '0');
  int minute = (s[2] - '0') * 10 + (s[3] - '0');

  if (roundup) {
    while (minute % 5) ++minute;
    if (minute == 60) { ++hour; minute = 0; }
  } else {
    while (minute % 5) --minute;
  }

  return hour * 12 + minute / 5;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> cnt(12 * 24 + 1, 0);

  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    std::string s1 = s.substr(0, 4);
    std::string s2 = s.substr(5, 4);
    ++cnt[func(s1, false)];
    --cnt[func(s2, true)];
  }
  for (int i = 1; i < (int)cnt.size(); ++i) cnt[i] += cnt[i - 1];

  if (cnt[0] > 0) std::cout << "0000-";
  for (int i = 1; i < (int)cnt.size(); ++i) {
    if (cnt[i - 1] == 0 && cnt[i] > 0) {
      int hour = i / 12;
      int minute = (i % 12) * 5;
      if (hour < 10) std::cout << "0";
      std::cout << hour;
      if (minute < 10) std::cout << "0";
      std::cout << minute << "-";
    }
    if (cnt[i - 1] > 0 && cnt[i] == 0) {
      int hour = i / 12;
      int minute = (i % 12) * 5;
      if (hour < 10) std::cout << "0";
      std::cout << hour;
      if (minute < 10) std::cout << "0";
      std::cout << minute << std::endl;
    }
  }
  return 0;  
}
