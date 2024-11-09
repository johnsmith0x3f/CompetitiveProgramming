#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	vector<vector<int>> f(n + 1, vector<int>(2, 0));
	f[0][0] = 0, f[0][1] = -1e9;
	for(int i = 1, mx = 0; i <= n; ++i) {
		f[i][0] = f[i - 1][0];
		if(f[i][0] < a[i]) ++f[i][0];
		if(f[i][0] > a[i]) --f[i][0];

		f[i][1] = f[i - 1][1];
		if(f[i][1] < a[i]) ++f[i][1];
		if(f[i][1] > a[i]) --f[i][1];

		f[i][1] = max(f[i][1], mx), mx = max(mx, f[i][0]);
	}

	cout << f[n][1] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
