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
		vector<int> a(n);
		for(int i = 0; i < n; ++i) a[i] = read();

		if(n == 1) {
			printf("%d\n", k + (a[0] < k) - 1);
			continue;
		}

		int d = 0;
		for(int i = 0; i < n; ++i) d = gcd(d, a[i]);
		printf("%lld\n", d > 1 ? 1ll * min(k / (d-1), n-1) * d + k - min(k / (d-1), n-1) * (d-1) - (k / (d-1) <= n-1 && k % (d-1) == 0) : k + n-1);
	}
	return 0;
}

