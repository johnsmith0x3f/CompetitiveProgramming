#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i];

		int ans = 0;
		sort(a.begin(), a.end());
		for(int i = 0, j = 0; i < n; j = max(j, ++i)) {
			while(j + 1 < n && a[j + 1] < min(a[i] + k, a[j] + 2)) ++j;
			ans = max(ans, j - i + 1);
		}
		cout << ans << "\n";
	}
	
	return 0;
}
