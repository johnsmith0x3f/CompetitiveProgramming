#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e5 + 5;
const int P = 1e9 + 7;
i64 fact[N], invFact[N];

inline i64 binExp(i64 a, int b = P - 2) {
	i64 c = 1;
	while(b) {
		if(b & 1) c = c * a % P;
		a = a * a % P, b >>= 1;
	}
	return c;
}

inline i64 Perm(const int &n, const int &m) {
	return (n < 0 || m < 0 || n < m) ? 0 : fact[n] * invFact[n - m] % P;
}

inline i64 Comb(const int &n, const int &m) {
	return (n < 0 || m < 0 || n < m) ? 0 : Perm(n, m) * invFact[m] % P;
}

inline void init(int n) {
	fact[0] = 1;
	for(int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % P;
	invFact[n] = binExp(fact[n]);
	for(int i = n; i >= 1; --i) invFact[i - 1] = invFact[i] * i % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	init(n);

	i64 ans = 0;
	for(int i = 0; i <= k; ++i) {
		ans += (i & 1 ? -1 : 1) * Comb(k, i) * (Perm(n - i, k - i) - 1) % P;
		ans %= P;
	}

	cout << (ans + P) % P << '\n';

	return 0;
}
