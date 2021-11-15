#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
	int s;
	std::cin >> s;
	bool possible = false;
	for (int a = 1; a < s; ++a) {
	    for (int b = 1; b < s; ++b) {
		if (4 * a * b + 3 * a + 3 * b == s) possible = true;
	    }
	}
	if (!possible) ++res;
    }
    std::cout << res << std::endl;
}
