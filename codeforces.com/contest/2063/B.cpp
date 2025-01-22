#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n, l, r;
	cin >> n >> l >> r;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	i64 lans = 0, rans = 0;

	vector<int> la;
	for(int i = 1; i <= r; ++i) la.emplace_back(a[i]);
	sort(begin(la), end(la));
	for(int i = 0; i < r - l + 1; ++i) lans += la[i];

	vector<int> ra;
	for(int i = l; i <= n; ++i) ra.emplace_back(a[i]);
	sort(begin(ra), end(ra));
	for(int i = 0; i < r - l + 1; ++i) rans += ra[i];

	cout << min(lans, rans) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
