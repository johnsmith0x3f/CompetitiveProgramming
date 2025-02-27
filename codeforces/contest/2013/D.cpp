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
i64 a[N];

inline bool check1(const int &n, const i64 &x) {
	i64 res = 0;
	for(int i = 1; i <= n; ++i) res = a[i] + max(res - x, 0ll);
	return res <= x;
}

inline bool check2(const int &n, const i64 &x) {
	i64 res = x;
	for(int i = n; i >= 1; --i) res = a[i] - max(x - res, 0ll);
	return res >= x;
}

int main() {
	int cas = read();
	while(cas--) {
		int n = read();
		for(int i = 1; i <= n; ++i) a[i] = read<i64>();

		i64 L = 1, R = 1e18;

		for(i64 l = L, r = R; l <= r; ) {
			i64 m = (l + r) >> 1;
			if(check1(n, m)) R = m, r = m - 1;
			else l = m + 1;
		}

		for(int i = 1; i < n; ++i)
			if(a[i] > R) a[i+1] += a[i] - R, a[i] = R;

		for(i64 l = L, r = R; l <= r; ) {
			i64 m = (l + r) >> 1;
			if(check2(n, m)) L = m, l = m + 1;
			else r = m - 1;
		}

		printf("%lld\n", R - L);
	}
	return 0;
}

