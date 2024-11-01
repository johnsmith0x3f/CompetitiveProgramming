#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	int u = 2;
	vector<int> p(n, 0);
	while(u < n) {
		cout << "? 1 " << u << "\n", cout.flush();

		int r;
		cin >> r;

		if(r == 0) {
			p[u++] = 1;
			break;
		}
		u++;
	}

	int i = 1;
	for(int j = u; j < n; ++j) {
		cout << "? " << j - 1 << " " << j << "\n", cout.flush();

		int r;
		cin >> r;

		if(r) {
			while(r) {
				cout << "? " << ++i << " " << j << "\n", cout.flush();

				cin >> r;
			}
			p[j] = i;
		}
		else p[j] = j - 1;
	}

	cout << "! ";
	for(int i = 1; i < n; ++i) cout << p[i] << " \n"[i == n - 1];
	cout.flush();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
