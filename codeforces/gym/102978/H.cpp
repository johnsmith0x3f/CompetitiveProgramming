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

const int N = 105;
const int S = 10005;
const int P = 998244353;
int a[N], b[N], s[N];
i64 f[S];

template <typename T = int, const T p = P>
constexpr T binExp(const T &a, T b = p - 2) {
	T res = 1;
	for(T x = a; b; x = 1ll * x * x % p, b >>= 1)
		if(b & 1) res = 1ll * res * x % p;
	return res;
}

int main() {
	int n = read(), m = read();
	for(int i = 1; i <= n; ++i) a[i] = read(), s[i] = s[i-1] + a[i];
	for(int i = 1; i <= m; ++i) b[i] = read();

	f[0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = s[i]; j >= a[i]; --j) f[j] -= f[j - a[i]], f[j] %= P;
	
	i64 ans = 0;
	for(int i = 1; i <= m; ++i)
		for(int j = 0; j <= s[n]; ++j) ans += f[j] * b[i] % P * binExp(b[i] + j) % P, ans %= P;
	printf("%lld\n", (n + m - ans + P) % P);
	return 0;
}

