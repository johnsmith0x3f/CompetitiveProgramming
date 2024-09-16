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

const int N = 1000006;
int r[26], sum[N];

int main() {
	int n = read(), k = read(), l = read();
	string s, t;
	cin >> s >> t;
	s = "~" + s, t = "~" + t;

	for(int i = 1; i <= l; ++i) r[t[i] - 'a'] = 1;
	for(int i = 1; i <= n; ++i) sum[i] = sum[i-1] + r[s[i] - 'a'];

	i64 ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += upper_bound(sum+1, sum+n+1, sum[i-1] + k) - lower_bound(sum+1, sum+n+1, sum[i-1] + k);
	}
	printf("%lld\n", ans);
	return 0;
}

