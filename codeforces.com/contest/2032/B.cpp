#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n, k;
	cin >> n >> k;

	if(n == 1) {
		cout << "1\n1\n";
		return;
	}

	if(k == 1 || k == n) cout << "-1\n";
	else cout << "3\n1 " << k - (k & 1) << " " << k + 1 + (k & 1) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
