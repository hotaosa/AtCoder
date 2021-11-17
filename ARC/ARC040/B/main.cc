#include <iostream>
#include <vector>

int main() {
    int n, r;
    std::string s;
    std::cin >> n >> r >> s;

    std::vector<bool> painted(n, false);
    int last = -1;
    for (int i = 0; i < n; ++i) {
	if (s[i] == 'o') painted[i] = true;
	else last = i;
    }

    if (last == -1) { std::cout << "0" << std::endl; return 0; }

    int res = 0, pos = 0;
    while (true) {
	if (pos + r - 1 >= last) {
	    ++res;
	    break;
	} else if (painted[pos]) {
	    ++res;
	    ++pos;
	} else {
	    ++res;
	    for (int i = 0; i < r; ++i) painted[pos + i] = true;
	}
    }

    std::cout << res << std::endl;    
    return 0;
}
