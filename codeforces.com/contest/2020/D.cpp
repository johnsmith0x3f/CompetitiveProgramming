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

const int N = 200005;
int fa[N], far[N][15];

int find(const int &x) {
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

int farind(const int &x, const int &d) {
	return far[x][d] == x ? far[x][d] : far[x][d] = farind(far[x][d], d);
}

inline void solve() {
	int n = read(), m = read();

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= 10; ++j) fa[i] = far[i][j] = i;

	while(m--) {
		int a = read(), d = read(), k = read(), p = a;
		while((farind(p, d) - a) / d < k) fa[find(p)] = find(far[p][d] + d), p = (far[p][d] += d);
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i) ans += find(i) == i;
	printf("%d\n", ans);
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

