#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	for(int i = 1; i < n; ++i)
		if(a[i - 1] == a[i] + 1) swap(a[i - 1], a[i]);

	cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}

