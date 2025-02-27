#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	int ans = 0;
	for(int i = 0; i < 15; ++i) {
		if(i % 3 == i % 5) ans += n / 15 * i + (n % 15 >= i);
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
