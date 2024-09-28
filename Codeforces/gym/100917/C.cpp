#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

int main() {
	i64 n = read<i64>(), ans = 0;
	for(i64 i = 1; i < n; ++i) {
		i64 sum = 1 + i, nxt = i * i;
		while(sum <= n) ans += (n % sum == 0), sum += nxt, nxt *= i;
	}
	printf("%lld\n", ans);
	return 0;
}

