#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n;
	cin >> n;

	vector<i64> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	i64 ans = 0;
	for(int i = 1; i <= n; ++i) ans += a[i];

	for(int i = n; i > 1; --i) {
		for(int j = 1; j < i; ++j) a[j] = a[j + 1] - a[j];

		i64 sum = 0;
		for(int j = 1; j < i; ++j) sum += a[j];
		ans = max(ans, max(sum, -sum));
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
