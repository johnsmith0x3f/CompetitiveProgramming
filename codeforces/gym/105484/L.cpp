#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int a[4] = { 3, 0, 2, 1 };
const int b[8] = { 0, 5, 1, 4, 2, 7, 3, 6 };
int p[N];

inline void solve() {
	int n;
	cin >> n;

	if(n <= 2 || n != (n & -n)) {
		cout << "No" << '\n';
		return;
	}
	cout << "Yes" << '\n';

	if(__lg(n) & 1) {
		int m = 8;
		for(int i = 0; i < 8; ++i) p[i] = b[i];
		while(m < n) {
			for(int i = 0; i < m * 4; ++i) p[i] = p[i % m];
			for(int i = 0; i < m * 4; ++i) p[i] ^= m * a[i / m];
			m *= 4;
		}
	}
	else {
		int m = 4;
		for(int i = 0; i < 4; ++i) p[i] = a[i];
		while(m < n) {
			for(int i = 0; i < m * 4; ++i) p[i] = p[i % m];
			for(int i = 0; i < m * 4; ++i) p[i] ^= m * a[i / m];
			m *= 4;
		}
	}

	for(int i = 0; i < n; ++i) cout << i << " \n"[i == n - 1];
	for(int i = 0; i < n; ++i) cout << p[i] << " \n"[i == n - 1];

	// for(int i = 0; i < n; ++i) cout << (i ^ p[i]) << " \n"[i == n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
