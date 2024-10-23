#include <bits/stdc++.h>
using namespace std;

inline void BFS(const int &k, vector<int> &dst, vector<vector<int>> &G) {
	queue<int> q;
	dst.assign(dst.size(), -1);

	dst[1] = 0, q.push(1);
	while(q.size()) {
		int v = q.front(); q.pop();
		for(int u : G[v])
			if(!~dst[u]) dst[u] = (dst[v] + 1) % k, q.push(u);
	}
}

inline void KMP(vector<int> &s, vector<int> &t, vector<int> &match) {
	int n = s.size(), m = t.size();

	vector<int> next(m, 0);
	for(int i = 1, j = 0; i < m; ++i) {
		while(j && t[i] != t[j]) j = next[j - 1];
		next[i] = (j += t[i] == t[j]);
	}

	for(int i = 0, j = 0; i < n; ++i) {
		while(j && s[i] != t[j]) j = next[j - 1];
		if((j += s[i] == t[j]) == m) match[i - m + 1] = 1, j = next[j - 1];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n + 1);
		for(int i = 1; i <= n; ++i) cin >> a[i];

		int m1;
		cin >> m1;
		vector<vector<int>> G1(n + 1);
		for(int i = 1; i <= m1; ++i) {
			int v, u;
			cin >> v >> u;
			G1[v].push_back(u);
		}

		vector<int> b(n + 1);
		for(int i = 1; i <= n; ++i) cin >> b[i];

		int m2;
		cin >> m2;
		vector<vector<int>> G2(n + 1);
		for(int i = 1; i <= m2; ++i) {
			int v, u;
			cin >> v >> u;
			G2[v].push_back(u);
		}

		int i1 = 0, o1 = 0, i2 = 0, o2 = 0;
		for(int i = 1; i <= n; ++i) i1 += (a[i] ^ 1), o1 += a[i];
		for(int i = 1; i <= n; ++i) i2 += (b[i] ^ 1), o2 += b[i];
		if(i1 != o2 || i2 != o1) {
			cout << "NO\n";
			continue;
		}
		if(i1 == n || i2 == n) {
			cout << "YES\n";
			continue;
		}

		vector<int> d1(n + 1), d2(n + 1);
		BFS(k, d1, G1), BFS(k, d2, G2);

		vector<int> s1(k), t1(k), s2(k), t2(k);
		for(int i = 1; i <= n; ++i) ++(a[i] ? t1 : s2)[d1[i]];
		for(int i = 1; i <= n; ++i) ++(b[i] ? t2 : s1)[d2[i]];
		s1.insert(s1.end(), s1.begin(), s1.end());
		s2.insert(s2.end(), s2.begin(), s2.end());

		vector<int> mt1(k + 1), mt2(k + 1);
		KMP(s1, t1, mt1), KMP(s2, t2, mt2);

		int flag = 0;
		for(int i = 0; i < k; ++i) {
			if(mt1[i] && mt2[(k - i + 2) % k]) {
				flag = 1;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}
