#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

const int N = 200005;
int deg[N], inq[N];
vector<int> to[N];
set<pair<int, int>> edge, ss;

int main() {
	int n = read(), m = read();
	for(int i = 1; i <= m; ++i) edge.insert({ read(), read() });

	for(auto &[ u, v ] : edge) {
		if(edge.find({ v, u }) == edge.end()) ++deg[v];
		else to[u].push_back(v), to[v].push_back(u);
	}
	queue<int> q;
	for(int i = 1; i <= n; ++i)
		if(deg[i]) q.push(i), inq[i] = 1;
	while(q.size()) {
		int u = q.front();
		q.pop(), inq[u] = 0;
		for(int v : to[u]) {
			if(deg[v]) continue;
			ss.erase({ deg[v], v }), ++deg[v], ss.insert({ deg[v], v });
			if(!inq[v]) q.push(v), inq[v] = 1;
		}
	}

	int flag = 1;
	for(int i = 1; i <= n; ++i) flag &= (deg[i] > 0);
	puts(flag ? "YES" : "NO");
	return 0;
}

