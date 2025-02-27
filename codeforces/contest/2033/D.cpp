#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	vector<i64> s(n + 1);
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

	map<i64, int> last;
	vector<int> dp(n + 1);
	for(int i = 0; i <= n; ++i) {
		dp[i] = dp[i - (i > 0)];
		if(last.count(s[i])) dp[i] = max(dp[i], dp[last[s[i]]] + 1);
		last[s[i]] = i;
	}

	cout << dp[n] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
