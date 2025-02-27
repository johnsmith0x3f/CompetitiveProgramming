#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	bool win = true;
	for(int i = 0; i < n; ++i)
		if(a[i] < max(i * 2 + 1, (n - i) * 2 - 1)) win = false;

	cout << (win ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
