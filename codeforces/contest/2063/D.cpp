#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n, m;
	cin >> n >> m;

	vector<i64> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(begin(a) + 1, end(a));
	for(int i = 1; i <= n / 2; ++i) a[i] = a[i - 1] + a[n - i + 1] - a[i];
	
	vector<i64> b(m + 1);
	for(int i = 1; i <= m; ++i) cin >> b[i];
	sort(begin(b) + 1, end(b));
	for(int i = 1; i <= m / 2; ++i) b[i] = b[i - 1] + b[m - i + 1] - b[i];

	vector<i64> ans;
	for(int k = 1; k <= n + m; ++k) {
		int l = max(0, 2 * k - m);
		int r = min(k, n - k);

		if(l > r) break;

		while(r - l > 5) {
			int lm = l + (r - l) / 3, rm = r - (r - l) / 3;
			if(a[lm] + b[k - lm] < a[rm] + b[k - rm]) l = lm;
			else r = rm;
		}

		i64 temp = 0;
		for(int i = l; i <= r; ++i) temp = max(temp, a[i] + b[k - i]);
		ans.emplace_back(temp);
	}

	cout << ans.size() << '\n';
	for(i64 x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
