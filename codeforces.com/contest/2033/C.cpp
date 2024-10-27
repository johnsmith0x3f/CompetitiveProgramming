#include <bits/stdc++.h>
using namespace std;

using ai = array<int, 3>;

const int INF = 0x3f3f3f3f;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		vector<int> a(n + 2);
		for(int i = 1; i <= n; ++i) cin >> a[i];

		vector<vector<int>> f(n + 1, vector<int>(2, INF)); f[0][0] = f[0][1] = 0;
		for(int i = 1, j = n; i <= j; ++i, --j)
			for(auto [ s, l, r ] : { ai{ 0, i, j }, ai{ 1, j, i } })
				for(auto [ t, x, y ] : { ai{ 0, i - 1, j + 1 }, ai{ 1, j + 1, i - 1 } })
					f[i][s] = min(f[i][s], f[i - 1][t] + (a[l] == a[x]) + (a[r] == a[y]));

		int m = (n + 1) / 2;
		cout << min(f[m][0], f[m][1]) + ((n & 1) ^ 1) * (a[m] == a[m + 1]) << "\n";
	}

	return 0;
}
