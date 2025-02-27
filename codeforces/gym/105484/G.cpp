#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int rt, fa[N], ls[N], rs[N], siz[N];

inline int big(const int &v) {
	return max(siz[rt] - siz[v], max(siz[ls[v]], siz[rs[v]]));
}

void getSize(int v) {
	if(v == 0) return;
	getSize(ls[v]), getSize(rs[v]), siz[v] = siz[ls[v]] + siz[rs[v]] + 1;
}

inline void solve() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) fa[i] = ls[i] = rs[i] = 0;

	for(int i = 1; i <= n; ++i) {
		cin >> ls[i] >> rs[i];
		if(ls[i]) fa[ls[i]] = i;
		if(rs[i]) fa[rs[i]] = i;
	}

	for(int i = 1; i <= n; ++i)
		if(fa[i] == 0) rt = i;

	while(1) {
		for(int i = 1; i <= n; ++i) siz[i] = 0;

		getSize(rt);
		if(siz[rt] == 1) break;

		int c = 1;
		for(int i = 1; i <= n; ++i)
			if(big(i) < big(c)) c = i;

		if(ls[c] == 0 || rs[c] == 0 || siz[rt] - siz[c] == siz[rt] / 2) {
			int u = fa[c], v = max(ls[c], rs[c]);
			if(u == 0) u = c;
			if(v == 0) v = c;
			cout << "? " << u << ' ' << v << '\n', cout.flush();

			int t;
			cin >> t;

			fa[c] = 0;
			if(ls[u] == c) ls[u] = 0;
			if(rs[u] == c) rs[u] = 0;

			fa[v] = 0;
			if(ls[c] == v) ls[c] = 0;
			if(rs[c] == v) rs[c] = 0;

			if(t == 1) rt = c;
			if(t == 2) rt = v;
		}
		else {
			int u = ls[c], v = rs[c];
			cout << "? " << u << ' ' << v << '\n', cout.flush();

			int t;
			cin >> t;

			fa[u] = fa[v] = 0;
			ls[c] = rs[c] = 0;

			if(t == 0) rt = u;
			if(t == 2) rt = v;
		}
	}

	cout << "! " << rt << '\n', cout.flush();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
