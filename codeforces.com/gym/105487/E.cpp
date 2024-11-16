#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int fa[N];

int find(const int &x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void solve() {
	int n;
	cin >> n;

	vector<vector<int>> sons(n + 1);
	for(int i = 1; i <= n; ++i) {
		int c;
		cin >> c;
		for(int j = 1; j <= c; ++j) {
			int x;
			cin >> x;
			sons[i].push_back(x);
		}
	}

	for(int i = 1; i <= n; ++i) fa[i] = i;

	for(int i = n; i >= 1; --i) {
		for(int v : sons[i]) {
			cout << i << ' ' << find(v) << '\n';
			fa[fa[v]] = i;
		}
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
