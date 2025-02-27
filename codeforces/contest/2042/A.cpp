#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(begin(a), end(a), greater<int>());

	int sum = 0;
	for(int i = 0; i < n; ++i) {
		if(sum + a[i] <= k) sum += a[i];
		else break;
	}

	cout << k - sum << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
