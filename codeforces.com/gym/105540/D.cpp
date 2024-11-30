#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

const int N = 1050;
pair<int, int> f[N][N];
stack<int> st;

struct Node {
	int a, x, b, y;
} ver[N];

pii DFS(int v, int t) {
	auto &[ a, x, b, y ] = ver[v];
	if(a == t) {
		if(t == 0) return { 1, 0 };
		return { 1, x };
	}
	
	if(f[v][t] != make_pair(0, 0)) return f[v][t];

	int loop = 0, now = v, top = t, num = 0;
	while(1) {
		if(++loop > 2e6) {
			cout << "-1" << '\n';
			exit(0);
		}

		auto [ x, y ] = DFS(now, top);
		num += x;
		if(ver[y].a == b) {
			return f[v][t] = ;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;

		if(s[0] == 'P') {
			int a, x, b, y;
			cin >> a >> x >> b >> y;

			ver[i] = { a, x, b, y };
		}
		else {
			int b, y;
			cin >> b >> y;

			ver[i] = { 0, 0, b, y };
		}
	}

	cout << DFS(1).first << '\n';

	return 0;
}
