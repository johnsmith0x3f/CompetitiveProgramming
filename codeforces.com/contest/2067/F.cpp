#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

const int P = 1e9 + 7;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	vector<int> p(n + 1);
	for(int i = 0; i < n; ++i) p[i + 1] = p[i] ^ a[i];

	map<int, i64> dp; dp[0] = 1;
	for(int i = 1; i <= n; ++i) dp[p[i - 1]] = (dp[p[i - 1]] * 3 + dp[p[i]] * 2) % P;

	i64 ans = 0;
	for(auto [ _, x ] : dp) ans += x;
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
