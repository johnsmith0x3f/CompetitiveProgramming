#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	int ans = n - 1;
	for(int i = 0, j = 1; j < n; ++i, ++j) {
		int pos = lower_bound(a.begin(), a.end(), a[i] + a[j]) - a.begin();
		ans = min(ans, n - pos + i);
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
