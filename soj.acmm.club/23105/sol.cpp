#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

const int P = 1e9 + 7;

inline void solve() {
	int A, B, n;
	cin >> A >> B >> n;

	if(n == 0) {
		cout << 2 << '\n';
		return;
	}

	if(n == 1) {
		cout << A << '\n';
		return;
	}

	i64 x = 2, y = A, z = 0;
	for(int i = 2; i <= n; ++i) z = (y * A - x * B) % P, x = y, y = z;

	cout << (z + P) % P << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}