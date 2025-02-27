#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vint = vector<int>;

inline void solve() {
	int n;
	cin >> n;

	vector<int> x(n), y(n), z(n);
	for(int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];

	vector<map<int, vint>> p(3);
	for(int i = 0; i < n; ++i) {
		p[0][x[i]].emplace_back(i);
		p[1][y[i]].emplace_back(i);
		p[2][z[i]].emplace_back(i);
	}

	vector<pii> lines;
	for(int i = 0; i < 3; ++i)
		for(auto &[ j, k ] : p[i]) lines.emplace_back(i, j);
	sort(lines.begin(), lines.end(), [&](const pii &a, const pii &b) {
		return p[a.first][a.second].size() > p[b.first][b.second].size();
	});

	vector<int> ans(n + 1, n);

	int temp = n;
	vector<bool> vst(n);
	for(auto &[ i, j ] : lines) {
		for(int &k : p[i][j]) {
			if(vst[k]) continue;
			vst[k] = 1, ans[int(p[i][j].size()) - 1] = --temp;
		}
	}

	for(int i = n - 1; ~i; --i) ans[i] = min(ans[i], ans[i + 1]);
	for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
