#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		vector<vector<int>> a(n, vector<int>(n));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) cin >> a[i][j];

		vector<int> low(n + n);
		for(int i = 0; i < n; ++i)
	  		for(int j = 0; j < n; ++j) low[i - j + n] = min(low[i - j + n], a[i][j]);

		i64 ans = 0;
		for(int i = 1; i < n + n; ++i) ans -= low[i];
		cout << ans << "\n";
	}

	return 0;
}
