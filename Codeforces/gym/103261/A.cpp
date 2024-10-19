#include <bits/stdc++.h>
using namespace std;

const int N = 4e6 + 5;
const int INF = 0x3f3f3f3f;
int n, m, tot = 1, h[N], cur[N];
int dep[N];

int start_time = 0;

struct Edge {
	int u, v, c, n;
} e[N * 3];

inline void addEdge(const int &u, const int &v, const int &c) {
	e[++tot] = { u, v, c, h[u] };
	h[u] = tot;
	e[++tot] = { v, u, 0, h[v] };
	h[v] = tot;
}

int BFS() {
	queue<int> q;
	memset(dep, 0, sizeof(dep));

	dep[0] = 1, q.push(0);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = h[u]; i; i = e[i].n) {
			int v = e[i].v;
			if(!dep[v] && e[i].c) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return dep[n];
}

int DFS(int u, int res) {
	if(u == n || res == 0) return res;

	int flow = 0;
	for(int &i = cur[u]; i; i = e[i].n) {
		int v = e[i].v, c = e[i].c, temp = 0;
		if(dep[v] == dep[u] + 1 && (temp = DFS(v, min(res, c))) > 0) {
			res -= temp, flow += temp;
			e[i].c -= temp, e[i ^ 1].c += temp;
		}
		if(res == 0) break;
	}
	return flow;
}

int dinic() {
	int ret = 0;
	while(BFS() && clock() - start_time < 7.5 * CLOCKS_PER_SEC) {
		memcpy(cur, h, sizeof(cur));
		ret += DFS(0, INF);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	start_time = clock();

	int n1, n2;
	cin >> n1 >> n2 >> m;
	n = n1 + n2 + 1;

	for(int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v + n1, 1);
	}

	for(int i = 1; i <= n1; ++i) addEdge(0, i, 1);
	for(int i = 1; i <= n2; ++i) addEdge(i + n1, n, 1);

	cout << dinic() << "\n";
	for(int i = 1; i <= m; ++i)
		if(e[i * 2].c == 0) cout << i << "\n";

	return 0;
}
