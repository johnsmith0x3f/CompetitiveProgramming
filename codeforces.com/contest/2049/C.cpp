#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n, x, y;
	cin >> n >> x >> y; --x, --y;

	vector<int> a(n);
	if(((n ^ 1) & 1) && ((x ^ y) & 1)) {
		for(int i = 0; i < n; ++i) a[i] = i & 1;
	}
	else {
		a[x] = 2;
		for(int i = 0; i < n; ++i)
			if(i != x) a[i] = ((i - x + n) % n) & 1;
	}
	
	for(int i = 1; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}