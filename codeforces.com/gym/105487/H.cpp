#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	double ans = 0.0;
	for(int i = 0, j = 1, l = s.size(); i < l; i = j++) {
		if(s[i] == '0') continue;

		while(j < l && s[j] == s[i]) ++j;
		ans += (j - i) / 2 + ((j - i) & 1 ? 1 : sqrt(2) - 1);
	}

	cout << fixed << setprecision(10) << ans << '\n';

	return 0;
}
