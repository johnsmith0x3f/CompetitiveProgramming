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
int b[N];

inline void solve() {
	int n = read(), m = read(), q = read();
	for(int i = 1; i <= m; ++i) b[i] = read();
	sort(b+1, b+m+1);

	while(q--) {
		int a = read();
		int l = lower_bound(b+1, b+m+1, a) - b - 1;
		int r = upper_bound(b+1, b+m+1, a) - b;

		if(a == b[r-1]) printf("0\n");
		else if(l == 0) printf("%d\n", b[r] - 1);
		else if(r == m+1) printf("%d\n", n - b[l]);
		else printf("%d\n", (b[r] - b[l]) / 2);
	}
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

