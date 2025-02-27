#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int c[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> r(n);
	for(int i = 0; i < n; ++i) cin >> r[i];
	
	int num = 0, ans = 0;
	vector<vector<int>> I(m * 2), S(m * 2);
	for(int i = 0; i < n; ++i) {
		if(r[i] == 0) ++num;
		else {
			if(num >= m * 2) ++ans;
			else if(r[i] > 0) I[num].push_back(+r[i]);
			else if(r[i] < 0) S[num].push_back(-r[i]);
		}
	}
	for(int i = 0; i < m * 2; ++i) {
		sort(I[i].begin(), I[i].end());
		sort(S[i].begin(), S[i].end());
	}

	vector<vector<int>> f(m * 2, vector<int>(m + 1));
	for(int i = 1; i < m * 2; ++i) {
		for(int j = 0; j <= min(i, m); ++j) {
			int foo = upper_bound(I[i].begin(), I[i].end(), j) - I[i].begin();
			int bar = upper_bound(S[i].begin(), S[i].end(), i - j) - S[i].begin();
			f[i][j] = max(f[i][j], f[i - 1][j] + foo + bar);
			if(j) f[i][j] = max(f[i][j], f[i - 1][j - 1] + foo + bar);
		}
	}

	int bns = 0;
	for(int i = 0; i <= m; ++i) bns = max(bns, f[m * 2 - 1][i]);
	cout << ans + bns << "\n";

	return 0;
}
