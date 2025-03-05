#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

const int N = 3e5 + 5;
const int P = 998244353;

inline void solve() {
	int n;
	cin >> n;

	vector<int> p(n + 1);
	for(int i = 2; i <= n; ++i) cin >> p[i];

	vector<int> d(n + 1);
	for(int i = 1; i <= n; ++i) d[i] = d[p[i]] + 1;

	vector<vector<int>> vs(n + 1);
	for(int i = 1; i <= n; ++i) vs[d[i]].emplace_back(i);

	vector<i64> dp(n + 1), sum(n + 1);
	dp[1] = sum[1] = 1;

	for(int i = 2; i <= n; ++i) {
		for(int v : vs[i]) {
			dp[v] = (sum[d[v] - 1] - (p[v] == 1 ? 0 : dp[p[v]]) + P) % P;
			sum[d[v]] = (sum[d[v]] + dp[v]) % P;
		}
	}

	i64 ans = 0;
	for(int i = 1; i <= n; ++i) ans = (ans + dp[i]) % P;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
