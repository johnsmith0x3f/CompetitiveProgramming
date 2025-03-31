#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int L = 60;
i64 dp[L][L][L];

inline void init() {
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0] = 0;

	auto checkmin = [](i64 &a, i64 b) {
		a = a < b ? a : b;
	};

	for (int i = 1; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			for (int k = 0; k < L; ++k) {
				if (i + j < L) checkmin(dp[i][i + j][k], dp[i - 1][j][k] + (1LL << i));
				if (i + k < L) checkmin(dp[i][j][i + k], dp[i - 1][j][k] + (1LL << i));
			}
		}
		for (int j = 0; j < L; ++j)
			for (int k = 0; k < L; ++k) checkmin(dp[i][j][k], dp[i - 1][j][k]);
	}
}

inline void solve() {
	i64 x, y;
	cin >> x >> y;

	i64 ans = 1e18;
	for (int i = 0; i < L; ++i)
		for (int j = 0; j < L; ++j)
			if ((x >> i) == (y >> j)) ans = min(ans, dp[L - 1][i][j]);

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
