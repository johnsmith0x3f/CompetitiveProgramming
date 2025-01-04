#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int l, r;
	cin >> l >> r;

	int ans = 0;
	for(int i = 30; i > 0; --i) {
		if(((l >> i) ^ (r >> i)) & 1) {
			int k = (1 << i);
			if(l < ans + k - 1) cout << ans + k - 2 << ' ' << ans + k - 1 << ' ' << ans + k << '\n';
			else cout << ans + k - 1 << ' ' << ans + k << ' ' << ans + k + 1 << '\n';
			return;
		}
		ans |= (l & (1 << i));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
