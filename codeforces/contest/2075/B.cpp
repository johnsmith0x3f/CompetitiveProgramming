#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	if (k == 1) {
		i64 ans = 0;
		for (int i = n - 1; i > 0; --i) ans = max(ans, (i64)a[i] + a[0]);
		for (int i = 0; i < n - 1; ++i) ans = max(ans, (i64)a[i] + a[n - 1]);

		cout << ans << '\n';
		return;
	}

	sort(rbegin(a), rend(a));

	i64 ans = 0;
	for (int i = 0; i <= k; ++i) ans += a[i];

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
