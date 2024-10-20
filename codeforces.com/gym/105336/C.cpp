#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

const int N = 100005;
int ans, c[N];
vector<int> to[N];

int DFS(int u, int p) {
	int siz = 1;
	for(int v : to[u])
		if(v != p) siz += max(DFS(v, u), c[u] - 1);
	if(c[u]) return ans += siz / 2, -((siz & 1) ^ 1);
	else return siz;
}

inline void solve() {
	int n = read(), m = read();
	for(int i = 1; i <= n; ++i) c[i] = 0, to[i].clear();
	for(int i = 1; i <= m; ++i) c[read()] = 1;
	for(int i = 2; i <= n; ++i) {
		int u = read(), v = read();
		to[u].push_back(v), to[v].push_back(u);
	}

	ans = 0;
	for(int i = 1; i <= n; ++i)
		if(c[i]) { DFS(i, 0); break; }

	printf("%d\n", ans);
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

