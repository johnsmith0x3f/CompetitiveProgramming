#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<vector<int>> G(n + 1);
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v), G[v].emplace_back(u);
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j : G[i]) ans = max(ans, int(G[i].size() + G[j].size()) - 2);

	multiset<int> S;
	for(int i = 1; i <= n; ++i) S.insert(G[i].size());

	for(int i = 1; i <= n; ++i) {
		S.erase(S.find(G[i].size()));
		for(int j : G[i]) S.erase(S.find(G[j].size()));

		if(S.size()) ans = max(ans, int(G[i].size() + *S.rbegin()) - 1);

		S.insert(G[i].size());
		for(int j : G[i]) S.insert(G[j].size());
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
