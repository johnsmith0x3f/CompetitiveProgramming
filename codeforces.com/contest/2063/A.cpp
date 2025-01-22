#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int l, r;
	cin >> l >> r;

	cout << r - l + (l == 1 && r == 1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
