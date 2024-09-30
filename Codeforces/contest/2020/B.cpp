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

int main() {
	int cas = read();
	while(cas--) {
		i64 k = read<i64>(), las = 0, now = sqrt(k);
		while(now - las > 0) k += now - las, las = now, now = sqrt(k);
		printf("%lld\n", k);
	}
	return 0;
}

