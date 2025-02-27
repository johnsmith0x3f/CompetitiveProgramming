#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n, k;
	cin >> n >> k;

	map<int, int> num;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++num[x];
	}

	vector<int> c;
	for(auto [ _, x ] : num) c.emplace_back(x);
	sort(begin(c), end(c));

	int ans = c.size();
	for(int i = 0; i + 1 < c.size(); ++i) {
		if(k < c[i]) break;
		k -= c[i], --ans;
	}
	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
