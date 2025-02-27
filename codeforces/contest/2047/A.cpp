#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	int sum = 0, ans = 0;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		int y = sqrt(sum += x);
		if((y & 1) && y * y == sum) ++ans;
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