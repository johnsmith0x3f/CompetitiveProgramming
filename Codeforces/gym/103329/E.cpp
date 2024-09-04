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
int a[N], b[N];
i64 pa[N], pb[N];

inline void solve() {
	int n = read();
	for(int i = 1; i <= n; ++i) a[i] = read(), b[i] = read();
	for(int i = 1; i <= n; ++i) pa[i] = pa[i-1] + a[i], pb[i] = pb[i-1] + b[i] - a[i];

	for(int i = 1, j = 1; i <= n; i = ++j) {
		if(a[i]) continue;
		while(j < n && !a[j+1]) ++j;
		if(2ll * (pb[j] - pb[i-1]) > pb[n] + pa[i-1]) return void(puts("NO"));
	}
	puts("YES");
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

