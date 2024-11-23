#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int tot, pr[N], d[N];
bool isprime[N];

inline void init() {
	for(int i = 2; i < N; ++i) isprime[i] = 1;

	for(int i = 2; i < N; ++i) {
		if(isprime[i]) pr[++tot] = i, d[i] = i;
		for(int j = 1; j <= tot && i * pr[j] < N; ++j) {
			isprime[i * pr[j]] = 0, d[i * pr[j]] = pr[j];
			if(i % pr[j] == 0) break;
		}
	}
}

inline void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> S(m + 1);
	for(int i = 1; i <= m; ++i) cin >> S[i];

	vector<int> id(n + 1, m);
	for(int i = 2; i <= n; ++i) {
		id[i] = id[i / d[i]] - 1;
		if(id[i] == 0) {
			cout << "-1\n";
			return;
		}
	}

	for(int i = 1; i <= n; ++i) cout << S[id[i]] << " \n"[i == n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
