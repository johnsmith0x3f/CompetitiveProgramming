#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 3e5 + 5;
int dep[N], siz[N];
vector<int> G[N];

void DFS(int v, int p) {
	siz[v] = 1;
	for(int u : G[v])
		if(u != p) dep[u] = dep[v] + 1, DFS(u, v), siz[v] += siz[u];
}

inline void solve() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) G[i].clear();
	for(int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v), G[v].emplace_back(u);
	}

	DFS(1, 0);

	vector<int> num(n + 1), sum(n + 2);
	for(int i = 1; i <= n; ++i) ++num[dep[i]];
	for(int i = n; i >= 0; --i) sum[i] = sum[i + 1] + num[i];

	i64 foo = 0;
	for(int i = 1; i <= n; ++i) foo += 2LL * dep[i] * (sum[dep[i]] - siz[i]);
	for(int i = 1; i <= n; ++i) foo -= 1LL * i * num[i] * (num[i] - 1);

	i64 bar = 0;
	for(int v = 1; v <= n; ++v) {
		i64 temp = 0;
		for(int u : G[v])
			if(dep[u] > dep[v]) temp += 1LL * siz[u] * (siz[v] - siz[u] - 1);
		bar += temp * dep[v] + temp / 2;
	}

	cout << foo - bar << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
