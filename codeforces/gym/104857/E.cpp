#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<int, vector<int>> x, y;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			int c;
			cin >> c;
			x[c].push_back(i), y[c].push_back(j);
		}
	}

	i64 ans = 0;
	for(auto &[ c, v ] : x) {
		sort(v.begin(), v.end());
		
		i64 sum = 0;
		for(int i = 0; i < v.size(); ++i) ans += 1ll * i * v[i] - sum, sum += v[i];
	}
	for(auto &[ c, v ] : y) {
		sort(v.begin(), v.end());
		
		i64 sum = 0;
		for(int i = 0; i < v.size(); ++i) ans += 1ll * i * v[i] - sum, sum += v[i];
	}

	cout << ans * 2 << "\n";

	return 0;
}
