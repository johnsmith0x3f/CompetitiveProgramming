#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int P = 1e9 + 7;
int p[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p[0] = 1;
	for(int i = 1; i < N; ++i) p[i] = 2ll * p[i - 1] % P;

	int t;
	cin >> t;

	vector<int> n(t), k(t);
	for(int i = 0; i < t; ++i) cin >> n[i];
	for(int i = 0; i < t; ++i) cin >> k[i];

	for(int i = 0; i < t; ++i) cout << (k[i] == n[i] ? 1 : p[k[i]]) << "\n";

	return 0;
}
