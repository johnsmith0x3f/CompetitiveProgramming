#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<string> s(n);
	for(int i = 0; i < n; ++i) cin >> s[i];

	auto check = [&](const string &str) -> int {
		return (str != s[0].substr(0, k)) + (str != s[0].substr(k, k)) + (str != s[1].substr(0, k));
	};

	map<string, int> num;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(check(s[i].substr(j * k, k)) > 1) {
				cout << i + 1 << ' ' << j + 1 << '\n';
				return 0;
			}
		}
	}

	return 0;
}
