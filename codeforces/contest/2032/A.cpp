#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	int num = 0;
	for(int i = 0; i < n * 2; ++i) {
		int x;
		cin >> x;
		num += x;
	}

	cout << (num & 1) << " " << min(num, n) - max(num - n, 0) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
