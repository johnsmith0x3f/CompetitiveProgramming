#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int dep[N], far[N][2], fa[N][21], st[N][21];
vector<int> e[N];

void getFar(int v, int p) {
	dep[v] = dep[p] + 1;
	for(int u : e[v]) {
		if(u == p) continue;
		getFar(u, v);

		if(far[u][0] + 1 > far[v][1]) far[v][1] = far[u][0] + 1;
		if(far[v][1] > far[v][0]) swap(far[v][1], far[v][0]);
	}
}

void getAns(int v, int p) {
	fa[v][0] = p;
	st[v][0] = far[p][far[p][0] == far[v][0] + 1] - dep[p];

	for(int i = 0; i < 20; ++i) {
		fa[v][i + 1] = fa[fa[v][i]][i];
		st[v][i + 1] = max(st[v][i], st[fa[v][i]][i]);
	}

	for(int u : e[v])
		if(u != p) getAns(u, v);
}

inline void solve() {
	int n;
	cin >> n;

	for(int i = 2; i <= n; ++i) {
		int v, u;
		cin >> v >> u;
		e[v].push_back(u), e[u].push_back(v);
	}

	getFar(1, 0);
	getAns(1, 0);

	int q;
	cin >> q;
	while(q--) {
		int v, k;
		cin >> v >> k;
		k = min(k, dep[v] - 1);

		int u = v, ans = far[u][0];
		for(int i = 20; i >= 0; --i)
			if((k >> i) & 1) ans = max(ans, st[u][i] + dep[v]), u = fa[u][i];

		cout << ans << " \n"[q == 0];
	}

	for(int i = 1; i <= n; ++i) {
		dep[i] = far[i][0] = far[i][1] = 0, e[i].clear();
		for(int j = 0; j < 21; ++j) fa[i][j] = st[i][j] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
