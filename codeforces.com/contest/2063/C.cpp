#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> deg(n + 1);
	vector<vector<int>> G(n + 1);

	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v), ++deg[v];
		G[v].emplace_back(u), ++deg[u];
	}

	if(n == 2) {
		cout << 0 << '\n';
		return;
	}

	vector<int> id(n + 1);
	iota(begin(id), end(id), 0);
	sort(begin(id) + 1, end(id), [&](int i, int j) { return deg[i] > deg[j]; });

	vector<bool> adj(n + 1);
	for(int x : G[id[1]]) adj[x] = true;

	int v = 2;
	while(v <= n && adj[id[v]]) ++v;

	if(v == 2) cout << 1 + deg[id[1]] - 1 + deg[id[2]] - 1 << '\n';
	else cout << 1 + max(deg[id[1]] - 1 + deg[id[2]] - 1 - 1, max(v <= n ? deg[id[1]] - 1 + deg[id[v]] - 1 : 0, deg[id[2]] - 1 + deg[id[3]] - 1)) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
