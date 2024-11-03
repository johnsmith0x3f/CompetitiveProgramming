#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n;
	cin >> n;

	int m = sqrt(n);
	i64 ans = 1, las = 1;
	for(int i = 1; i <= m; ++i)
		if(n % i == 0) ans += (i - las) * (n / las), las = i;
	for(int i = m; i >= 1; --i)
		if(n % i == 0) ans += (n / i - las) * (n / las), las = n / i;

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
