#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template<typename T = int>
inline T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

const int N = 100005;
int tim, tin[N], low[N], ins[N];
vector<int> cut, to[N];

void tarjan(int u, int p) {
	tin[u] = low[u] = ++tim;
	int kid = 0, flag = 0;
	for(int v : to[u]) {
		if(tin[v] == 0) {
			++kid, tarjan(v, u), low[u] = min(low[u], low[v]);
			if(u != p && low[v] >= tin[u]) flag = 1;
		}
		else if(v != p) low[u] = min(low[u], tin[v]);
	}
	if((u == p && kid > 1) || flag) cut.push_back(u);
}

int main() {
	int n = read(), m = read();
	for(int i = 1; i <= m; ++i) {
		int u = read(), v = read();
		to[u].push_back(v), to[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i)
		if(tin[i] == 0) tarjan(i, i);
	sort(cut.begin(), cut.end());

	int ss = cut.size();
	printf("%d\n", ss);
	for(int i = 0; i < ss; ++i) printf("%d%c", cut[i], " \n"[i == ss-1]);
	return 0;
}

