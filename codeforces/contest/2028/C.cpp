#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n, m, v;
	cin >> n >> m >> v;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	vector<i64> s(n + 1, 0);
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

	vector<int> lp(1, 0), rp(1, n + 1);
	int foo = 0, bar = 0;
	for(int i = 1; i <= n; ++i)
		if((foo += a[i]) >= v) lp.push_back(i), foo = 0;
	for(int i = n; i >= 1; --i)
		if((bar += a[i]) >= v) rp.push_back(i), bar = 0;

	i64 ans = 0;
	for(int i = 0, j = m; i <= m; ++i, --j)
		if(i < lp.size() && j < rp.size()) ans = max(ans, s[rp[j] - 1] - s[lp[i]]);

	if(lp.size() < m + 1 && rp.size() < m + 1) cout << "-1\n";
	else cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
