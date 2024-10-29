#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	vector<i64> s(n + 1, 0);
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + (a[i] == a[i - 1]) * a[i];

	int mx = 0;
	for(int i = 1; i <= n; ++i) mx = max(mx, a[i]);

	vector<int> h(mx + 1, 0), las(n + 1, 0);
	for(int i = 1; i <= n; ++i) las[i] = h[a[i]], h[a[i]] = i;

	vector<vector<i64>> f(n + 1, vector<i64>(2, 0));
	for(int i = 1; i <= n; ++i) {
		if(a[i] == a[i - 1]) {
			f[i][0] = max(f[i - 1][0], f[i - 1][1]) + a[i];
			f[i][1] = max(f[i - 1][0], f[i - 1][1]) + s[i] - s[las[i]];
		}
		else {
			f[i][0] = max(f[i - 1][0], f[i - 1][1]);
			f[i][1] = max(f[i][0], f[las[i] + 1][1] + s[i] - s[las[i] + 1] + a[las[i]]);
		}
	}

	cout << max(f[n][0], f[n][1]) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
