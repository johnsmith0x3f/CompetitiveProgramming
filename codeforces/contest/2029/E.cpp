#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
int tot, d[N], pr[N];
bool isprime[N];

inline void sieve() {
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
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	int x = 2;
	for(int i = 0; i < n; ++i)
		if(isprime[a[i]]) x = a[i];

	for(int i = 0; i < n; ++i)
		if(a[i] != x && a[i] - (a[i] & 1) * d[a[i]] < 2 * x) x = -1;

	cout << x << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	sieve();

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
