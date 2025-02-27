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

const int N = 250005;
const int P = 998244353;
int x[N], vst[N];

template <typename T = int, const T p = P>
constexpr T binExp(const T &a, T b = p - 2) {
	T res = 1;
	for(T x = a; b; x = 1ll * x * x % p, b >>= 1)
		if(b & 1) res = 1ll * res * x % p;
	return res;
}

int main() {
	int n = read(), m = read();
	for(int i = 1; i <= m; ++i) x[i] = read(), vst[x[i]] = 1;

	int mx = 0;
	for(int i = 1; i <= m; ++i) {
		vst[x[i]] = 2, mx = max(mx, x[i]);
		if(x[i] > x[i+1]) break;
	}

	i64 ans = 1, num = 0;
	for(int i = 1; i <= n; ++i) {
		if(vst[i] == 0) ans *= num, ans %= P, ++num;
		else if(vst[i] == 2) num += 1 + (i >= mx);
	}
	printf("%lld\n", ans);
	return 0;
}

