#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int x, y, k;
	cin >> x >> y >> k;

	if(x > y) swap(x, y);
	cout << "0 0 " << x << ' ' << x << '\n' << "0 " << x << ' ' << x << " 0\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
