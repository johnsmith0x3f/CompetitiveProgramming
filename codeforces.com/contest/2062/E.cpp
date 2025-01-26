#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
int tim, L[N], R[N], w[N], id[N];
vector<int> E[N];

void DFS(int v, int p) {
	L[v] = R[v] = ++tim;
	for(int u : E[v])
		if(u != p) DFS(u, v), R[v] = R[u];
}

inline void solve() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) cin >> w[i], E[i].clear();
	for(int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v), E[v].emplace_back(u);
	}

	DFS(1, 0);

	for(int i = 1; i <= n; ++i) id[i] = i;
	sort(id + 1, id + n + 1, [&](int i, int j) {
		if(w[i] != w[j]) return w[i] > w[j];
		return L[i] > L[j];
	});

	for(int i = 1, j = 2; i <= n; i = j++) {
		while(j <= n && w[id[j]] == w[id[i]]) ++j;

		if(j > n) break;

		int k = i;
		while(k < j) {
			if(L[id[k]] < L[id[j]] || R[id[j]] < L[id[k]]) return cout << id[j] << '\n', void();
			++k;
		}
		while(k <= n && w[id[k]] == w[id[j]]) {
			if(R[id[k]] < L[id[j]]) return cout << id[k] << '\n', void();
			++k;
		}
	}

	cout << 0 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
