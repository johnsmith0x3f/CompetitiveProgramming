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

const int N = 1000006;
int c[N];
i64 p[N], q[N], ans[N];
char s[N];

inline void solve() {
	int n = read(); i64 C = read();
	for(int i = 1; i <= n; ++i) s[i] = getchar();
	for(int i = 1; i <= n; ++i) {
		c[i] = read(), p[i-1] = q[i+1] = 0, ans[i] = 1e18;
		if(s[i] == s[n-i+1]) c[i] = 0;
	}

	int b = -1, e = -1;
	for(int i = 1; i <= n; ++i)
		if(s[i] != s[n-i+1]) (~b ? e : b) = i;
	int l = -1, r = -1;
	for(int i = 1; i <= n; ++i)
		if(s[i] != s[n-i+1] && i < n-i+1) l = i, r = n-i+1;

	if(!~b && !~e) {
		for(int i = 1; i <= n; ++i) printf("0%c", " \n"[i == n]);
		return;
	}

	for(int i = b; i <= e; ++i) {
		p[i] = p[i-1] + c[i];
		if(i > n-i+1) p[i] -= max(c[i], c[n-i+1]);
	}
	for(int i = b; i < l; ++i) p[i] = 1e18;
	i64 foo = 1e18, bar = 1e18;
	for(int i = e; i >= b; --i) {
		foo = min(foo, p[i] + C * (i+i-b));
		bar = min(bar, p[i] + C * (i-b-b));
		ans[i] = min(ans[i], min(foo - C * i, bar + C * i));
	}

	for(int i = e; i >= b; --i) {
		q[i] = q[i+1] + c[i];
		if(i < n-i+1) q[i] -= max(c[i], c[n-i+1]);
	}
	for(int i = e; i > r; --i) q[i] = 1e18;
	i64 baz = 1e18, qux = 1e18;
	for(int i = b; i <= e; ++i) {
		baz = min(baz, q[i] + C * (e-i-i));
		qux = min(qux, q[i] + C * (e+e-i));
		ans[i] = min(ans[i], min(baz + C * i, qux - C * i));
	}

	for(int i = 1; i < b; ++i) ans[i] = ans[b] + 1ll * C * (b-i);
	for(int i = n; i > e; --i) ans[i] = ans[e] + 1ll * C * (i-e);

	for(int i = 1; i <= n; ++i) printf("%lld%c", ans[i], " \n"[i == n]);
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

