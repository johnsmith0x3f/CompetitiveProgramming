#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	set<int> ss;
	for(int i = 0; i < n; ++i) {
		if(ss.size() && *ss.rbegin() > a[i] + 1) {
			cout << "NO\n";
			return;
		}
		ss.insert(a[i]);
	}

	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}

