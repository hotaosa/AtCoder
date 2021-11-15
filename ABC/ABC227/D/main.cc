#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    long long l = 0LL, r = 1e18 / k;
    while (r - l > 1LL) {
	long long m = (l + r) / 2LL;
	long long sum = 0LL;
	for (long long x : a) sum += std::min(x, m);
	if (sum >= k * m) l = m;
	else r = m;
    }
    std::cout << l << std::endl;
    return 0;
}
