#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	cout << (n & 1 ? "Kosuke" : "Sakurako") << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
