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
	i64 a = 0, b = read<i64>(), c = read<i64>(), d = read<i64>();

	for(int i = 0; i < 60; ++i) {
		i64 p = -1, x = (b >> i) & 1, y = (c >> i) & 1, z = (d >> i) & 1;
		for(int k : { 0, 1 })
			if((k | x) - (k & y) == z) p = k;

		if(!~p) return void(puts("-1"));

		a |= p << i;
	}
	printf("%lld\n", a);
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

