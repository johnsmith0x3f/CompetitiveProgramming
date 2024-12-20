#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1, 0);
	for(int i = 0; i < n; ++i) cin >> a[i];

	int num = 0;
	for(int i = 0; i < n; ++i)
		num += (a[i] != 0 && a[i + 1] == 0);
	
	cout << min(num, 2) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}