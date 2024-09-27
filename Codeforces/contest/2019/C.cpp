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

inline void solve() {
	i64 n = read<i64>(), k = read<i64>();

	vector<i64> a(n);
	for(int i = 0; i < n; ++i) a[i] = read<i64>();

	i64 sum = 0, mx = 0;
	for(int i = 0; i < n; ++i) sum += a[i], mx = max(mx, a[i]);

	for(i64 i = n; i; --i)
		if((sum + k) / i >= mx && (sum + k) % i <= k) return void(printf("%lld\n", i));
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

