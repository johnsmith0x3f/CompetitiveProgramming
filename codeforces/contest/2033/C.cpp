#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	for(int i = 1, j = n; i < j; ++i, --j)
		if(a[i] == a[i - 1] || a[j] == a[j + 1]) swap(a[i], a[j]);

	int ans = 0;
	for(int i = 1; i < n; ++i) ans += (a[i] == a[i + 1]);

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
