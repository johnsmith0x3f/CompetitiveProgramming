#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<vector<int>> a(2, vector<int>(n));
	for(int i = 0; i < n; ++i) cin >> a[0][i];
	for(int i = 0; i < n; ++i) cin >> a[1][i];

	int foo = 0, bar = -1e9;
	for(int i = 0; i < n; ++i) foo += max(a[0][i], a[1][i]), bar = max(bar, min(a[0][i], a[1][i]));

	cout << foo + bar << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}