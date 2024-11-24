#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	i64 x, m;
	cin >> x >> m;
	
	int ans = 0;
	for(i64 y = 1; y <= min(x + x, m); ++y) {
		i64 z = x ^ y;
		if(z && (x % z == 0 || y % z == 0)) ++ans;
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
