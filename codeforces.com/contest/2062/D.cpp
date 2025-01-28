#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

inline void solve() {
	int n;
	cin >> n;

	vector<int> l(n), r(n);
	for(int i = 0; i < n; ++i) cin >> l[i] >> r[i];

	vector<vector<int>> E(n);
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}

	i64 ans = 0;
	vector<int> a(n);

	function<void(int, int)> DFS = [&](int v, int p) {
		int mx = l[v];
		for(int u : E[v])
			if(u != p) DFS(u, v), mx = max(mx, a[u]);
		a[v] = min(mx, r[v]);
		for(int u : E[v])
			if(u != p) ans += max(a[u] - a[v], 0);
	};

	DFS(0, 0);

	cout << a[0] + ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
