#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> start_day = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

    std::vector<bool> holiday(366, false);
    for (int i = 0; i < 366; ++i) if (i % 7 == 0 || i % 7 == 6) holiday[i] = true;

    for (int i = 0; i < n; ++i) {
	int m, d;
	char c;
	std::cin >> m >> c >> d;
	int day = start_day[m - 1] + d - 1;
	while (holiday[day]) ++day;
	holiday[std::min(day, 365)] = true;
    }

    int res = 0, cur = 0;
    for (auto h : holiday) {
	if (h) ++cur;
	else {
	    res = std::max(res, cur);
	    cur = 0;
	}
    }
    res = std::max(res, cur);
    std::cout << res << std::endl;
    return 0;
}
