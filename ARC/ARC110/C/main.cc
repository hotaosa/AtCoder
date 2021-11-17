#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n), pos(n);
    for (int i = 0; i < n; ++i) {
	std::cin >> p[i];
	--p[i];
	pos[p[i]] = i;
    }

    std::vector<int> res;
    std::vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
	if (pos[i] > i) {
	    for (int j = pos[i] - 1; j >= i; --j) {
		if (used[j]) {
		    std::cout << "-1" << std::endl;
		    return 0;
		}
		res.push_back(j + 1);
		used[j] = true;
		pos[p[j]] = j + 1;
		pos[p[j + 1]] = j;
		std::swap(p[j], p[j + 1]);
	    }
	}
    }

    if (res.size() < n - 1) std::cout << "-1" << std::endl;
    else for (int r : res) std::cout << r << std::endl;
    return 0;
}
    
