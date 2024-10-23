#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int C = 202025;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	i64 sum = 0;
	vector<vector<int>> s(101);
	for(int i = 0; i < n; ++i) {
		int p, w;
		cin >> p >> w;
		if(p == 100) sum += w;
		else s[p].push_back(w);
	}

	vector<double> f(C + 1, 0); f[0] = 1.0;
	for(int i = 1; i < 100; ++i) {
		sort(s[i].begin(), s[i].end(), greater<int>());
		for(int j = 0; j < s[i].size() && j < 100 / (100 - i); ++j)
			for(int k = C; k >= s[i][j]; --k) f[k] = max(f[k], f[k - s[i][j]] * i / 100);
	}

	double ans = 0.0;
	for(int i = 0; i <= C; ++i) ans = max(ans, f[i] * (sum + i));
	cout << fixed << setprecision(8) << ans << "\n";

	return 0;
}
