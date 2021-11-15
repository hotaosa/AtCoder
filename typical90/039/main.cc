#include <iostream>
#include <vector>
#include <algorithm>

void dfs(const std::vector<std::vector<int> > &graph, std::vector<long long> &dp, int v, int p = -1) {
    dp[v] = 1LL;
    for (int nv : graph[v]) {
	if (nv == p) continue;
	dfs(graph, dp, nv, v);
	dp[v] += dp[nv];
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > graph(n);
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n - 1; ++i) {
	int u, v;
	std::cin >> u >> v;
	a[i] = --u;
	b[i] = --v;
	graph[u].push_back(v);
	graph[v].push_back(u);
    }

    std::vector<long long> dp(n, -1LL);
    dfs(graph, dp, 0);

    long long res = 0LL;
    for (int i = 0; i < n; ++i) {
	long long r = std::min(dp[a[i]], dp[b[i]]);
	res += r * (n - r);
    }
    std::cout << res << std::endl;
    return 0;
}
