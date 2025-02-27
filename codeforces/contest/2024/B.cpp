#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());

		i64 ans = 0;
		for(int i = 0; i < n; ++i) {
			i64 temp = 1ll * (n - i) * (a[i] - (i ? a[i - 1] : 0));
			if(k <= temp) {
				ans += k;
				break;
			}
			k -= temp, ans += temp + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
