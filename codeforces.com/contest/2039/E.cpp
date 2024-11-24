#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int P = 998244353;

inline void solve() {
	int n;
	cin >> n;

	vector<i64> dp(n + 1);

	i64 pre = 0;
	for(int i = 3; i <= n; ++i) {
		dp[i] = (pre + 1) % P;
		pre = (pre + dp[i] * i - 1) % P;
	}

	i64 ans = 1;
	for(int i = 3; i <= n; ++i) ans += dp[i];
	cout << ans % P << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}