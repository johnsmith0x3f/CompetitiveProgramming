#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	i64 n, b, c;
	cin >> n >> b >> c;

	if(b == 0) {
		if(c < n - 2) cout << "-1\n";
		else cout << n - (c < n) << "\n";
	}
	else {
		if(c >= n) cout << n << "\n";
		else cout << n - ((n - c - 1) / b + 1) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
