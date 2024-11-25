#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e6 + 5;
const int P = 998244353;
i64 dp[N], ans[N];

inline void init(int n) {
	i64 pre = 0;
	for(int i = 3; i <= n; ++i) {
		dp[i] = (pre + 1) % P;
		pre = (pre + dp[i] * i - 1) % P;
	}

	ans[1] = 0, ans[2] = 1;
	for(int i = 3; i <= n; ++i) ans[i] = (ans[i - 1] + dp[i]) % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init(1e6);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << ans[n] << '\n';
	}

	return 0;
}
