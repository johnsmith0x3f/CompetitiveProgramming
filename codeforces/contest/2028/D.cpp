#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
pair<int, char> from[N];

void print(int v, int d) {
	if(v == 1) {
		cout << d << "\n";
		return;
	}
	print(from[v].first, d + 1);
	cout << from[v].second << " " << v << "\n";
}

inline void solve() {
	int n;
	cin >> n;

	vector<vector<int>> a(n + 1, vector<int>(3));
	for(int i = 1; i <= n; ++i) cin >> a[i][0];
	for(int i = 1; i <= n; ++i) cin >> a[i][1];
	for(int i = 1; i <= n; ++i) cin >> a[i][2];

	vector<int> x(3, 1);
	for(int i = 2; i <= n; ++i) {
		int p = -1;
		for(int j = 0; j < 3; ++j)
			if(a[x[j]][j] > a[i][j]) p = j;

		if(~p) {
			from[i] = { x[p], "qkj"[p] };
			for(int j = 0; j < 3; ++j)
				if(a[i][j] > a[x[j]][j]) x[j] = i;
		}
	}

	if(from[n].first) cout << "YES\n", print(n, 0);
	else cout << "NO\n";

	for(int i = 1; i <= n; ++i) from[i] = { 0, 0 };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
