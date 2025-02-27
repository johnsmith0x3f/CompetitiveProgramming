#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e5 + 5;
const int P = 998244353;
i64 fac[N], ifac[N], d[N][21];

inline i64 binExp(i64 a, int b = P - 2) {
	i64 c = 1;
	while(b) {
		if(b & 1) c = c * a % P;
		a = a * a % P, b >>= 1;
	}
	return c;
}

inline i64 C(int n, int m) {
	return (n < 0 || m < 0 || n < m) ? 0 : fac[n] * ifac[m] % P * ifac[n - m] % P;
}

inline void init(const int &n) {
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % P;
	ifac[n] = binExp(fac[n]);
	for(int i = n; i >= 1; --i) ifac[i - 1] = ifac[i] * i % P;

	for(int i = 1; i <= n; ++i) {
		d[i][1] = 1;
		for(int j = i + i; j <= n; j += i)
			for(int k = 1; k < 20; ++k) d[j][k + 1] = (d[j][k + 1] + d[i][k]) % P;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;

	init(m);

	i64 ans = 0;
	for(int i = 1; i <= m; ++i) {
		i64 temp = C(m - 1, n - 1);
		for(int j = 1; j <= 20; ++j) temp -= d[i][j] * C(m / i - 1, n - j) % P;
		ans += temp % P;
	}
	
	cout << (ans % P + P) % P << '\n';

	return 0;
}
