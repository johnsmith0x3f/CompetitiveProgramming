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

		int g = 0;
		for(int i = 0; i < n; ++i) g = gcd(g, a[i]);
		for(int i = 0; i < n; ++i) a[i] /= g;

		int d = 0; i64 ans = 0;
		for(int i = 0; i < n; ++i) {
			int x = 1e9;
			for(int i = 0; i < n; ++i) x = min(x, gcd(d, a[i]));
			ans += (d = x);

			if(d == 1) {
				ans += n - i - 1;
				break;
			}
		}
		printf("%lld\n", ans * g);
	}
	return 0;
}

