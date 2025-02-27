#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	i64 x, m;
	cin >> x >> m;
	
	i64 n = 1;
	while(n <= x) n <<= 1;

	vector<i64> a(n, 1e18);
	for(int i = x; i >= 1; --i) a[(x - i * n % x) % x] = i * n;

	i64 ans = m / a[0];
	for(i64 y = 1; y < n && y <= m; ++y) {
		i64 z = x ^ y;
		if(z % x == 0 || z % y == 0) ++ans;

		i64 t = y + a[z % x];
		if(t <= m) ans += (m - t) / a[0] + 1;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
