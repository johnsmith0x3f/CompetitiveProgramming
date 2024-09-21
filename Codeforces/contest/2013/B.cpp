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
		int n = read();
		vector<int> a(n);
		for(int i = 0; i < n; ++i) a[i] = read();

		i64 ans = a[n-1] - a[n-2];
		for(int i = 0; i < n - 2; ++i) ans += abs(a[i]);
		printf("%lld\n", ans);
	}
	return 0;
}

