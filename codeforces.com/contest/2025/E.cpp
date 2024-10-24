#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;
const int P = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> f(m + 2, vector<int>(m + 2, 0)); f[0][0] = 1;
	for(int i = 1; i <= m; ++i)
		for(int j = 0; j <= i; ++j)
			f[i][j] = ((j ? f[i - 1][j - 1] : 0) + f[i - 1][j + 1]) % P;

	vector<vector<int>> g(n + 1, vector<int>(m + 1, 0)); g[1][0] = 1;
	for(int i = 2; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			for(int k = 0; k <= j; ++k)
	   			g[i][j] = (g[i][j] + 1ll * g[i - 1][j - k] * f[m][k] % P) % P;

	int ans = 0;
	for(int i = 0; i <= m; ++i) ans = (ans + 1ll * f[m][i] * g[n][i] % P) % P;
	cout << ans << "\n";

	return 0;
}
