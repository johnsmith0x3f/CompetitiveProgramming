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
		int n = read(), k = read();

		if(k == 1) {
			printf("%d\n", n);
			continue;
		}

		int ans = 0;
		while(n) ans += n % k, n /= k;
		printf("%d\n", ans);
	}
	return 0;
}

