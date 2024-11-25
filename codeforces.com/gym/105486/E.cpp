#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e5 + 5;
const int P = 998244353;

int dep[N], fa[N][21];
vector<int> e[N];

i64 dp[N][2], pre[N][2];

inline i64 binExp(i64 a, int b = P - 2) {
	i64 c = 1;
	while(b) {
		if(b & 1) c = c * a % P;
		a = a * a % P, b >>= 1;
	}
	return c;
}

void DFS1(int v, int p) {
	dep[v] = dep[p] + 1, fa[v][0] = p;
	for(int i = 0; i < 20; ++i) fa[v][i + 1] = fa[fa[v][i]][i];

    dp[v][0] = 1;
    for(int u : e[v]) DFS1(u, v), dp[v][0] = dp[v][0] * (dp[u][0] + 1) % P;
}

void DFS2(int v, int p) {
	pre[v][0] = (pre[p][0] + dp[v][0] * (dp[v][1] + 1) % P) % P;
	pre[v][1] = (pre[p][1] + dp[v][0] * (dp[v][1] + 0) % P) % P;
	
	int m = e[v].size();
	vector<i64> foo(m, 1), bar(m, 1);
	for(int i = 0; i < m - 1; ++i) foo[i + 1] = foo[i] * (dp[e[v][i]][0] + 1) % P;
	for(int i = m - 1; i > 0; --i) bar[i - 1] = bar[i] * (dp[e[v][i]][0] + 1) % P;
	for(int i = 0; i < m; ++i) dp[e[v][i]][1] = (dp[v][1] + 1) * (foo[i] * bar[i] % P) % P;

	for(int u : e[v]) DFS2(u, v);
}

inline int LCA(int u, int v) {
	if(u == v) return u;
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 20; ~i; --i)
		if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if(u == v) return u;
	for(int i = 20; ~i; --i)
		if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

inline void solve() {
	int n, q;
	cin >> n >> q;

	for(int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		e[p].push_back(i);
	}

	DFS1(1, 0), DFS2(1, 0);

	while(q--) {
		int u, v;
		cin >> u >> v;

		int x = LCA(u, v);

        i64 temp = dp[x][0] * (dp[x][1] + 1) % P;
        temp += pre[u][0] + pre[v][0] - pre[x][0] - pre[x][0];
        temp -= pre[u][1] + pre[v][1] - pre[x][1] - pre[x][1];
        cout << (temp % P + P) % P << '\n';
    }

	for(int i = 1; i <= n; ++i) {
		dep[i] = dp[i][0] = dp[i][1] = pre[i][0] = pre[i][1] = 0, e[i].clear();
		for(int j = 0; j < 21; ++j) fa[i][j] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
