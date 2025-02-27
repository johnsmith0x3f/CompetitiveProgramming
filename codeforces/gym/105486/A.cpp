#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	string s;
	cin >> s;

	int n = s.size();

	int p = -1;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '-') {
			p = i;
		}
	}

	if(!~p || s[0] != '>' || s.substr(n - 3, 3) != ">>>") {
		cout << "No\n";
		return;
	}

	cout << "Yes ";

	vector<pair<int, int>> ans;
	for(int i = n; i > p + 3; --i) {
		ans.push_back({ 1, i });
	}
	for(int i = 1; i < p; ++i) {
		if(s[i] == '>') ans.push_back({ i + 1, p + 4 - i });
	}

	cout << ans.size() << "\n";
	for(auto &[ p, l ] : ans) cout << p << " " << l << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
