#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	map<string, int> num;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		++num[s];
	}

	for(auto &[ s, c ] : num)
		if(c + c > n) cout << s << "\n", exit(0);
	cout << "uh-oh\n";

	return 0;
}
