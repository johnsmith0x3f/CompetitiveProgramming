#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	int cc = 0, cp = 0;
	for(int i = 0; i < s.size(); ++i) cc += s[i] == 'C', cp += s[i] == 'P';

	cout << min((cc - 1) / 2, cp) << '\n';

	return 0;
}
