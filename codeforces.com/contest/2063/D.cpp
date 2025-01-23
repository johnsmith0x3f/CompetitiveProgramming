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

	int k = 0;
	vector<i64> f(n + m + 1);

	for(int i = 1; i <= n + m; ++i) {
		int l = max(0, i * 2 - m), r = min(i, n - i);
		while(r - l > 5) {
			int lm = l + (r - l) / 3, rm = r - (r - l) / 3;
			if(a[lm] + b[i - lm] < a[rm] + b[i - rm]) l = lm;
			else r = rm;
		}

		for(int j = l; j <= r; ++j) f[i] = max(f[i], a[j] + b[i - j]);

		if(f[i] > 0) k = i;
	}

	cout << k << '\n';
	for(int i = 1; i <= k; ++i) cout << f[i] << " \n"[i == k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
