#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	i64 x, m;
	cin >> x >> m;
	
	i64 n = 1;
	while(n <= x) n <<= 1;

	vector<i64> a(n, 1e18);
	for(int i = x; i >= 1; --i) a[i * n % x] = i * n;

	i64 ans = m / a[0];
	for(int y = 1; y < n && y <= m; ++y) {
		if((x ^ y) % x == 0 || (x ^ y) % y == 0) ++ans;

		i64 z = y + a[(x - (x ^ y) % x) % x];
		if(z <= m) {
			ans += 1 + (m - z) / a[0];
		}
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
