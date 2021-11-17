#include <iostream>
#include <vector>

int dist(int a, int b) {
    return a + b;
}

int main() {
    int r, c, d;
    std::cin >> r >> c >> d;
    std::vector<std::vector<int> > a(r, std::vector<int>(c));
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) std::cin >> a[i][j];

    int res = 0;
    for (int i = 0; i < r; ++i) {
	for (int j = 0; j < c; ++j) {
	    int di = dist(i, j);
	    if (di > d || (di + d) & 1) continue;
	    res = std::max(res, a[i][j]);
	}
    }

    std::cout << res << std::endl;
    
}
