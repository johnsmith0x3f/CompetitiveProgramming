#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

inline void solve() {
	i64 n, x, k;
	cin >> n >> x >> k;

	string s;
	cin >> s;
	s = '~' + s;

	i64 X = 0, Y = 0, sum = 0;
	for(int i = 1; i <= n; ++i) {
		sum += (s[i] == 'L') - (s[i] == 'R');
		if(!X && sum == x) X = i;
		if(!Y && sum == 0) Y = i;
	}

	cout << !!X * (1 + (!!Y ? (k - X) / Y : 0)) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
