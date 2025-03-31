#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(m);
	for (int i = 0; i < m; ++i) cin >> a[i];
	sort(begin(a), end(a));

	i64 ans = 0;
	for (int i = 1; i < n; ++i) {
		int x = end(a) - lower_bound(begin(a), end(a), i);
		int y = end(a) - lower_bound(begin(a), end(a), n - i);
		ans += 1LL * x * y - min(x, y);
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
