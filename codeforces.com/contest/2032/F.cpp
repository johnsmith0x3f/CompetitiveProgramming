#include <bits/stdc++.h>
using namespace std;

using vint = vector<int>;

const int P = 998244353;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	vector<int> pow(n, 1);
	for(int i = 1; i < n; ++i) pow[i] = pow[i - 1] * 2 % P;

	int l = -1;
	for(int i = 0; i < n; ++i) {
		if(a[i] > 1) {
			l = i;
			break;
		}
	}

	if(!~l) {
		cout << (n & 1) * pow[n - 1] << '\n';
		return;
	}

	int foo = pow[l], bar = 1;
	for(int i = 2; i <= l; i += 2) bar = (bar + pow[i - 1]) % P;

	int ans = 0, xsum = 0;
	for(int r = 0; r < n; ++r) {
		xsum ^= a[r];
		if(l <= r && xsum) ans = (ans + 1ll * (xsum == 1 ? foo : bar) * pow[max(n - r - 2, 0)] % P) % P;
	}

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
