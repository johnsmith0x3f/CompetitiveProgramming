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
		vector<int> p(n+1, 0);
		for(int i = 1; i <= n; ++i) p[i] = p[i-1] + read();

		i64 ans = 0;
		map<int, int> num;
		for(int len = 0; len <= n; ++len) {
			for(int l = 0, r = len; r <= n; ++l, ++r) {
				int s = p[l] + p[r];
				ans += len - 2 * num[s] - ((s & 1) || !binary_search(p.begin(), p.end(), s / 2)), ++num[s];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

