#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

const int N = 3e5 + 5;
const int P = 998244353;
i64 dep[N], sum[N], ans[N];
vector<int> G[N];

inline void solve() {
	int n;
	cin >> n;

	for(int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		G[p].push_back(i);
	}

	stack<int> st;
	auto BFS = [&]() {
		queue<int> q;
		q.push(1);

		while(q.size()) {
			int v = q.front();
			st.push(v), q.pop();
			for(int u : G[v]) dep[u] = dep[v] + 1, q.push(u);
		}
	};

	BFS();

	while(st.size()) {
		int v = st.top(); st.pop();

		ans[v] = sum[dep[v] + 1] + 1;
		for(int u : G[v]) ans[v] = (ans[v] - ans[u] + P) % P;
		sum[dep[v]] = (sum[dep[v]] + ans[v]) % P;
	}

	cout << (sum[1] + 1) % P << '\n';

	for(int i = 0; i <= n; ++i) sum[i] = 0, G[i].clear();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
