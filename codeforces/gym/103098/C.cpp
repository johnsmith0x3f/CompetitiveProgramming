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
int n[2], m[2], fa[2][N];

struct Edge {
	int t, u, v, w;
	bool operator < (const Edge &o) const {
		return w < o.w;
	}
};

inline int find(const int &t, const int &x) {
	return fa[t][x] == x ? x : fa[t][x] = find(t, fa[t][x]);
}

int main() {
	n[0] = read(), m[0] = read(), n[1] = read(), m[1] = read();
	vector<Edge> e(m[0]+m[1]);
	for(int i = 0; i < n[0] + n[1]; ++i) fa[0][i] = fa[1][i] = i;
	for(int i = 0; i < m[0] + m[1]; ++i) e[i] = { i >= m[0], read(), read(), read() };

	i64 ans = 0;
	sort(e.begin(), e.end());
	for(auto &[ t, u, v, w ] : e) {
		int fu = find(t, u), fv = find(t, v);
		if(fu != fv) --n[t], ans += 1ll * n[t^1] * w, fa[t][fv] = fu;
	}
	
	printf("%lld\n", ans);
	return 0;
}

