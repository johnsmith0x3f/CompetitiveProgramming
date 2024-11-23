#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	i64 x, m;
	cin >> x >> m;
	
	int ans = 0;
	for(i64 y = 1; y <= min(m, x + x); ++y) {
		if((x ^ y) && (x % (x ^ y) == 0 || y % (x ^ y) == 0)) ++ans;
	}
	
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
