#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int l, r;
	cin >> l >> r;

	int x = 0;
	for(int i = 30; i > 0; --i) {
		x |= r & (1 << i);
		if((l ^ r) >> i & 1) break;
	}

	int y = l < x - 1;
	cout << x - 1 - y << ' ' << x - y << ' ' << x + 1 - y << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
