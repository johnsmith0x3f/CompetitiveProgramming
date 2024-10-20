#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i];

		int mx = 0, mn = 1e9;
		for(int i = 0; i < n; ++i) mx = max(mx, a[i]), mn = min(mn, a[i]);

		cout << 1ll * (n - 1) * (mx - mn) << "\n";
	}
	return 0;
}
