#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	vector<int> pre(n + 2, 0);
	for(int i = 1; i <= n; ++i) pre[i] = max(pre[i - 1], a[i]);

	vector<int> suf(n + 2, 1e9);
	for(int i = n; i >= 1; --i) suf[i] = min(suf[i + 1], a[i]);

	int last = 0;
	for(int i = 1; i <= n; ++i) {
		if(pre[i] <= suf[i + 1]) {
			for(int k = i; k > last; --k) a[k] = max(a[k], pre[i]);
			last = i;
		}
	}

	for(int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
