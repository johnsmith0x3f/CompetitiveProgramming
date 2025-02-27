#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

inline void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> c(n + 1, vector<char>(m + 1));
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) cin >> c[i][j];

	int i = 1, j = 1, k = 0, now = 0;
	vector<vector<bool>> vst(n + 1, vector<bool>(m + 1, 0));
	vector<string> layer(n + m);
	for(int z = n * m; z >= 1; --z) {
		layer[now] += c[i][j], vst[i][j] = 1;

		int x = i + dx[k], y = j + dy[k];
		if(x < 1 || x > n || y < 1 || y > m || vst[x][y]) {
			k = (k + 1) % 4;
			if(k == 0) ++now;
		}
		i += dx[k], j += dy[k];
	}

	int ans = 0;
	for(int i = 0; i <= now; ++i) {
		layer[i] += layer[i];
		for(int j = 0; j < layer[i].size() / 2; ++j) ans += (layer[i].substr(j, 4) == "1543");
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
