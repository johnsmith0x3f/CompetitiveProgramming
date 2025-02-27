#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<bool> busy(n + 1, 0);
	for(int i = 1; i <= k; ++i) {
		int v;
		cin >> v;
		busy[v] = 1;
	}

	vector<vector<int>> e(n + 1);
	for(int i = 1; i <= m; ++i) {
		int v, u;
		cin >> v >> u;
		e[v].push_back(u), e[u].push_back(v);
	}

	if(k == n) return cout << "No\n", 0;

	int s = 1;
	while(busy[s]) ++s;

	vector<int> ans;
	vector<vector<int>> bns(n + 1);
	queue<int> q;
	vector<bool> vst(n + 1, 0);
	q.push(s), vst[s] = 1;
	while(q.size()) {
		int v = q.front(); q.pop();
		if(busy[v]) continue;

		ans.push_back(v);
		for(int u : e[v])
			if(!vst[u]) q.push(u), vst[u] = 1, bns[v].push_back(u);
		if(bns[v].empty()) ans.pop_back();
	}

	for(int i = 1; i <= n; ++i)
		if(!vst[i]) return cout << "No\n", 0;
	cout << "Yes\n";

	cout << ans.size() << "\n";
	for(int x : ans) {
		cout << x << " " << bns[x].size();
		for(int y : bns[x]) cout << " " << y;
		cout << "\n";
	}

	return 0;
}
