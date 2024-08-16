#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

int main() {
	int cas = read();
	while(cas--) {
		int n = read(), k = read();
		vector<int> a(n);
		for(int i = 0; i < n; ++i) a[i] = read();
		sort(a.begin(), a.end(), greater<int>());

		i64 ans = 0;
		for(int i = 0; i < n; ++i) {
			if(i % 2 == 0) ans += a[i];
			else ans -= a[i] + min(k, a[i-1] - a[i]), k -= min(k, a[i-1] - a[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}