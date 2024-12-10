#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];

	vector<vector<int>> to(n + 1);
	for(int i = 0; i < n; ++i) to[a[i]].push_back(b[i]), to[b[i]].push_back(a[i]);

	int ans = 1;
	vector<bool> vst(n + 1);

	for(int i = 1; i <= n; ++i) {
		if(vst[i]) continue;

		ans = ans * 2 % P;
		for(int j = i; !vst[j]; j = to[j][vst[to[j][0]]]) vst[j] = 1;
	}

	cout << ans << '\n';

	return 0;
}
