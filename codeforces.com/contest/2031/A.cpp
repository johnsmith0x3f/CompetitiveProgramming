#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	int mx = 0;
	for(int i = 0, j = 0; i < n; i = ++j) {
		while(j + 1 < n && a[j] <= a[j + 1]) ++j;
		mx = max(mx, j - i + 1);
	}

	cout << n - mx << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
