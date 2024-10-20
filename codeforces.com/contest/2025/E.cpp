#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;
const int P = 998244353;
int f[N], g[N], C[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	C[0][0] = 1;
	for(int i = 1; i <= m; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
	}

	for(int i = 0; i <= m; i += 2) f[i] = (C[m][m / 2 + i / 2] - C[m][m / 2 + i / 2 + 1] + P) % P;

	auto convol = [&](const int &n, int *f, int *g) {
		int res = 0;
		for(int i = 0; i <= n; ++i) res = (res + 1ll * f[i] * g[n - i] % P) % P;
		return res;
	};

	g[0] = 1;
	for(int i = 1; i < n; ++i)
		for(int j = m; j >= 0; j -= 2) g[j] = convol(j, f, g);

	int ans = 0;
	for(int i = 0; i <= m; i += 2) ans = (ans + 1ll * f[i] * g[i] % P) % P;
	cout << ans << "\n";

	return 0;
}
