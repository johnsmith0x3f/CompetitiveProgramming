#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	for(int i = 0; i < 5; ++i) {
		string t;
		getline(cin, t);

		for(int j = 0; j < t.size(); ++j)
			if(t[j] != ' ') s += t[j];
	}

	for(int i = 0; i < s.size(); ++i)
		if('A' <= s[i] && s[i] <= 'Z') s[i] += 'a' - 'A';

	int ans = 0;
	for(int i = 0; i + 2 < s.size(); ++i) ans += s.substr(i, 3) == "ass";

	cout << ans << '\n';

	return 0;
}