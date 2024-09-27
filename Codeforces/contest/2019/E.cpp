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

const int N = 500005;
int n, c[N], dep[N], far[N];
vector<int> to[N];

inline void update(int k, int x) {
	while(k <= n) c[k] += x, k += k & -k;
}

inline int query(int k) {
	int s = 0;
	while(k) s += c[k], k -= k & -k;
	return s;
}

void DFS(int u, int p) {
	far[u] = dep[u];
	for(int v : to[u])
		if(v != p) dep[v] = dep[u] + 1, DFS(v, u), far[u] = max(far[u], far[v]);
}

int main() {
	int cas = read();
	while(cas--) {
		n = read();

		for(int i = 1; i <= n; ++i) c[i] = 0, to[i].clear();

		for(int i = 2; i <= n; ++i) {
			int u = read(), v = read();
			to[u].push_back(v), to[v].push_back(u);
		}

		DFS(dep[1] = 1, 0);
		for(int i = 1; i <= n; ++i) update(1, 1), update(dep[i], -1), update(far[i] + 1, 1);

		int ans = n;
		for(int i = 1; i <= n; ++i) ans = min(ans, query(i));
		printf("%d\n", ans);
	}
	return 0;
}

