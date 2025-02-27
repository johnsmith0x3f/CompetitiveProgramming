#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> num(137);
	for(int i = 0; i < n; ++i) ++num[s[i]];

	int x = 0;
	for(int i = 0; i < n; ++i)
		if(num[s[i]] < num[s[x]]) x = i;
	--num[s[x]];

	int y = 0;
	for(int i = 0; i < n; ++i)
		if(num[s[i]] > num[s[y]]) y = i;
	s[x] = s[y];

	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}