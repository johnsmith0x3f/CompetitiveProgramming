#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> e[N];

int DFS(int v) {
	priority_queue<int, vector<int>, greater<int>> q;
	for(int u : e[v]) q.push(DFS(u));

	if(q.size() == 0) return 0;
	if(q.size() == 1) return q.top() + 1;

	while(q.size() > 1) {
		int x = q.top(); q.pop();
		int y = q.top(); q.pop();
		q.push(max(x, y) + 1);
	}
	return q.top();
}

inline void solve() {
	int n;
	cin >> n;

	for(int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		e[p].push_back(i);
	}

	cout << DFS(1) << '\n';

	for(int i = 1; i <= n; ++i) e[i].clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
