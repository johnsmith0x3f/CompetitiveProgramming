#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int x, y;
	cin >> x >> y;

	if(x + 1 == y) cout << "YES" << '\n';
	else if(x > y && (x - y) % 9 == 8) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
