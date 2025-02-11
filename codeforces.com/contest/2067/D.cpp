#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> x(n);
	for(int i = 0; i < n; ++i) cin >> x[i];

	vector<bool> vst(n + 1, false);
	for(int i = 0; i < n; ++i) vst[x[i]] = true;

	int foo = 0, bar = 0;
	for(int i = 1; i <= n; ++i) (vst[i] ? bar : foo) = i;
	if(foo && bar) {
		cout << "? " << foo << ' ' << bar << '\n';
		cout.flush();

		int ret;
		cin >> ret;
		if(ret == 0) cout << "! A" << '\n';
		else cout << "! B" << '\n';
		cout.flush();

		return;
	}

	for(int i = 0; i < n; ++i) {
		if(x[i] == 1) foo = i + 1;
		if(x[i] == n) bar = i + 1;
	}

	cout << "? " << foo << ' ' << bar << '\n';
	cout.flush();

	int ret;
	cin >> ret;
	if(ret == n - 1) {
		cout << "? " << bar << ' ' << foo << '\n';
		cout.flush();

		cin >> ret;
	}

	if(ret < n - 1) cout << "! A" << '\n';
	else cout << "! B" << '\n';
	cout.flush();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
