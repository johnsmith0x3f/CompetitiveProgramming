#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 2e5 + 1;
const int P = 998244353;
int g[N + 5], fac[N + 5], ifac[N + 5], temp[N + 5];

template <typename T = int, const T p = P>
constexpr T binExp(const T &a, T b = p - 2) {
	T res = 1;
	for(T x = a; b; x = 1ll * x * x % p, b >>= 1)
		if(b & 1) res = 1ll * res * x % p;
	return res;
}

inline int C(const int &n, const int &k) {
	return (n < 0 || k < 0 || n < k) ? 0 : 1ll * fac[n] * ifac[k] % P * ifac[n - k] % P;
}

int main() {
	fac[0] = 1;
	for(int i = 1; i <= N; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[N] = binExp(fac[N]);
	for(int i = N; i >= 1; --i) ifac[i - 1] = 1ll * ifac[i] * i % P;

	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i];

		vector<int> c(n, 0);
		for(int i = 0; i < n; ++i) ++c[a[i]];
		vector<int> suf(n + 1, 0);
		for(int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + c[i];

		int mn = 1e9;
		i64 ans = 0;
		fill(g, g + n + 1, 1);
		for(int i = 0; i < n; ++i) {
			mn = min(mn, c[i]), temp[c[i] + 1] = 0;
			for(int j = c[i]; j >= 0; --j) temp[j] = (temp[j + 1] + C(c[i], j)) % P;
			for(int j = 0; j <= c[i]; ++j) g[j] = 1ll * g[j] * temp[j] % P;

			for(int j = 1; j <= mn; ++j) ans = (ans + 1ll * j * (g[j] - (j < mn ? g[j + 1] : 0)) % P * binExp(2, suf[i + 1])) % P;
		}
		cout << (ans + P) % P << "\n";
	}
}
