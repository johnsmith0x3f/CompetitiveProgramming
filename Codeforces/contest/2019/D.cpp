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
int n, a[N], l[N], r[N], c[N];

inline void update(int k, int x) {
	while(k <= n) c[k] += x, k += k & -k;
}

inline int query(int k) {
	int s = 0;
	while(k) s += c[k], k -= k & -k;
	return s;
}

inline void solve() {
	n = read();
	for(int i = 1; i <= n; ++i) a[i] = read();

	for(int i = 1; i <= n; ++i) l[i] = n, r[i] = 0;
	for(int i = 1; i <= n; ++i) l[a[i]] = min(l[a[i]], i), r[a[i]] = max(r[a[i]], i);

	for(int i = 1; i <= n; ++i) c[i] = 0;

	int m = 0, L = n, R = 0;
	for(int i = 1; i <= n; ++i) {
		if(l[i] > r[i]) continue;

		m++, L = min(L, l[i]), R = max(R, r[i]);
		if(R - L >= i) return void(puts("0"));
		update(max(R - i, 0) + 1, 1), update(L + i, -1);
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i) ans += (query(i) >= m);
	printf("%d\n", ans);
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

