#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int l, r, k;
	cin >> l >> r >> k;

	cout << max(r / k - l + 1, 0) << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
