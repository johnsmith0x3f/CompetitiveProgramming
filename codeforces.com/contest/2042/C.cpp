#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n, k;
	cin >> n >> k;

	string str;
	cin >> str;

	vector<int> s(n + 1);
	for(int i = 0; i < n; ++i) s[i + 1] = s[i] + str[i] - '0';

	vector<int> d;
	for(int i = 1; i < n; ++i) {
		int temp = (s[n] - s[i]) * 2 - (n - i);
		if(temp >= 0) d.emplace_back(temp);
	}
	sort(d.begin(), d.end(), greater<int>());

	int sum = 0;
	for(int i = 0; i < d.size(); ++i) {
		if((sum += d[i]) >= k) {
			cout << i + 2 << '\n';
			return;
		}
	}

	cout << "-1" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
