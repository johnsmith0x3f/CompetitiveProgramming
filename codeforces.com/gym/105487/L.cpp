#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	if(A < 4) {
		cout << "0\n";
		return;
	}

	int ans = min(B, C) * 2 + 4;
	for(int i = 1; i <= B && i <= C && i <= D; ++i) ans = max(ans, (i + 2) * (min(D / i, min(B, C) - i) + 2));

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}