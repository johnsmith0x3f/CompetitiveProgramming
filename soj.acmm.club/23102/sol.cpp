#include <bits/stdc++.h>
using namespace std;

int DFS(int n) {
	if(n <= 2) return n;
	return min(DFS(n / 3) + n % 3, DFS(n / 4) + n % 4) + 1;
}

inline void solve() {
	int x;
	cin >> x;

	cout << DFS(x) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}