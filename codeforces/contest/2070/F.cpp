#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> s(m);
	for(int i = 0; i < m; ++i) {
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); ++j) s[i] |= 1 << (str[j] - 'A');
	}

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	int S = 0;
	for(int i = 0; i < n; ++i) S |= ((a[i] & 1) ^ 1) << i;

	for(int i = 0; i < m; ++i) {
		int T = (((1 << n) - 1) ^ s[i]) | S;
	}

	return 0;
}
